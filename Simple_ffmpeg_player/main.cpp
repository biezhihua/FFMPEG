#include <iostream>


extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <SDL2/SDL.h>
#include <libavutil/imgutils.h>
}

#define OUTPUT_YUV420P 0

int main() {

    AVFormatContext *pFormatCtx;
    int i, videoIndex;
    AVCodecContext *pCodecCtx;
    AVCodec *pCodec;
    AVFrame *pFrame, *pFrameYUV;
    unsigned char *out_buffer;
    AVPacket *packet;
    int y_size;
    int ret, got_picture;
    struct SwsContext *img_convert_ctx;

    char filePath[] = "/Users/biezhihua/Downloads/test.mkv";

    // SDL

    int screen_w = 0;
    int screen_h = 0;
    SDL_Window *screen;
    SDL_Renderer *sdlRenderer;
    SDL_Texture *sdlTexture;
    SDL_Rect sdlRect;

    FILE *fp_yuv;

    av_register_all();
    avformat_network_init();
    pFormatCtx = avformat_alloc_context();

    if (avformat_open_input(&pFormatCtx, filePath, NULL, NULL) != 0) {
        printf("Couldn't open input stream\n");
        return -1;
    }

    if (avformat_find_stream_info(pFormatCtx, NULL) < 0) {
        printf("Couldn't find stream information.\n");
        return -1;
    }

    AVDictionaryEntry *m = NULL;
    while(m = av_dict_get(pFormatCtx->metadata,"",m,AV_DICT_IGNORE_SUFFIX)) {
        printf("key:%s value:%s \n", m->key, m->value);
    }

    videoIndex = -1;

    for (int i = 0; i < pFormatCtx->nb_streams; ++i) {
        if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
            break;
        }
    }

    if (videoIndex == -1) {
        printf("Didn't find a video stream.\n");
        return -1;
    }

    pCodec = avcodec_find_decoder(pFormatCtx->streams[videoIndex]->codecpar->codec_id);
    pCodecCtx = avcodec_alloc_context3(pCodec);
    avcodec_parameters_to_context(pCodecCtx, pFormatCtx->streams[videoIndex]->codecpar);

    if (pCodec == NULL) {
        printf("Codec not found.\n");
        return -1;
    }

    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        printf("Could not open codec.\n");
        return -1;
    }

    pFrame = av_frame_alloc();
    pFrameYUV = av_frame_alloc();

    out_buffer = (unsigned char *) av_malloc(
            av_image_get_buffer_size(AV_PIX_FMT_YUV420P, pCodecCtx->width, pCodecCtx->height, 1));

    av_image_fill_arrays(pFrameYUV->data, pFrameYUV->linesize, out_buffer, AV_PIX_FMT_YUV420P, pCodecCtx->width,
                         pCodecCtx->height, 1);

    packet = (AVPacket *) av_malloc(sizeof(AVPacket));
    av_init_packet(packet);

    // output info
    av_dump_format(pFormatCtx, 0, filePath, 0);

    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt, pCodecCtx->width,
                                     pCodecCtx->height, AV_PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);

#if OUTPUT_YUV420P
    fp_yuv = fopen("output.yuv","wb+");
#endif

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        printf("Could not initialize SDL - %s\n", SDL_GetError());
        return -1;
    }

    screen_w = pCodecCtx->width;
    screen_h = pCodecCtx->height;

    // SDL
    screen = SDL_CreateWindow("Simplest ffmpeg player's Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h, SDL_WINDOW_OPENGL);
    if (!screen) {
        printf("SDL: could not create window - exiting:%s \n", SDL_GetError());
        return -1;
    }

    sdlRenderer = SDL_CreateRenderer(screen, -1, 0);

    sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, pCodecCtx->width,
                                   pCodecCtx->height);

    sdlRect.x = 0;
    sdlRect.y = 0;
    sdlRect.w = screen_w;
    sdlRect.h = screen_h;


    while (av_read_frame(pFormatCtx, packet) >= 0) {
        if (packet->stream_index == videoIndex) {
            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
            if (ret < 0) {
                printf("Decode Error.\n");
                return -1;
            }
            if (got_picture) {
                sws_scale(img_convert_ctx, (const uint8_t *const *) pFrame->data, pFrame->linesize, 0,
                          pCodecCtx->height, pFrameYUV->data,
                          pFrameYUV->linesize);

#if OUTPUT_YUV420P
                y_size = pCodecCtx->width * pCodecCtx->height;
                fwrite(pFrameYUV->data[0], 1, y_size, fp_yuv);
                fwrite(pFrameYUV->data[1], 1, y_size / 4, fp_yuv);
                fwrite(pFrameYUV->data[2], 1, y_size / 4 / fp_yuv);
#endif

#if 0
                SDL_UpdateTexture( sdlTexture, NULL, pFrameYUV->data[0], pFrameYUV->linesize[0] );
#else
                SDL_UpdateYUVTexture(sdlTexture, &sdlRect,
                                     pFrameYUV->data[0], pFrameYUV->linesize[0],
                                     pFrameYUV->data[1], pFrameYUV->linesize[1],
                                     pFrameYUV->data[2], pFrameYUV->linesize[2]);
#endif
                SDL_RenderClear(sdlRenderer);
                SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &sdlRect);
                SDL_RenderPresent(sdlRenderer);

                SDL_Delay(40);
            }
        }
        av_packet_unref(packet);
    }

    //flush decoder
    //FIX: Flush Frames remained in Codec
    while (1) {
        ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet);
        if (ret < 0)
            break;
        if (!got_picture)
            break;
        sws_scale(img_convert_ctx, (const unsigned char *const *) pFrame->data, pFrame->linesize, 0, pCodecCtx->height,
                  pFrameYUV->data, pFrameYUV->linesize);
#if OUTPUT_YUV420P
        int y_size=pCodecCtx->width*pCodecCtx->height;
        fwrite(pFrameYUV->data[0],1,y_size,fp_yuv);    //Y
        fwrite(pFrameYUV->data[1],1,y_size/4,fp_yuv);  //U
        fwrite(pFrameYUV->data[2],1,y_size/4,fp_yuv);  //V
#endif
        //SDL---------------------------
        SDL_UpdateTexture(sdlTexture, &sdlRect, pFrameYUV->data[0], pFrameYUV->linesize[0]);
        SDL_RenderClear(sdlRenderer);
        SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &sdlRect);
        SDL_RenderPresent(sdlRenderer);
        //SDL End-----------------------
        //Delay 40ms
        SDL_Delay(40);
    }

    sws_freeContext(img_convert_ctx);

#if OUTPUT_YUV420P
    fclose(fp_yuv);
#endif

    SDL_Quit();

    av_frame_free(&pFrameYUV);
    av_frame_free(&pFrame);
    avformat_close_input(&pFormatCtx);

    return 0;
}