#include <iostream>
#include <fstream>

extern "C" {
#include<libavformat/avformat.h>
#include<libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}
using namespace std;

int main() {
    int ret;
    int videoIndex = -1;
    int gotPicture;
    char filePath[] = "/Users/biezhihua/Downloads/biezhihua.mkv";

    av_register_all();
    avformat_network_init();
    AVFormatContext *pFormatContext = avformat_alloc_context();


    if (avformat_open_input(&pFormatContext, filePath, NULL, NULL) != 0) {
        cout << "Couldn't open input stream" << endl;
        return -1;
    }

    if (avformat_find_stream_info(pFormatContext, NULL) < 0) {
        cout << "Couldn't find stream information." << endl;
        return -1;
    }

    for (int i = 0; i < pFormatContext->nb_streams; ++i) {
        if (pFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
            break;
        }
    }

    if (videoIndex == -1) {
        cout << "Don't find a video stream." << endl;
        return -1;
    }

    AVFrame *pFrame = av_frame_alloc();
    AVCodecParameters *pCodecParameters = pFormatContext->streams[videoIndex]->codecpar;
    AVCodec *pCodec = avcodec_find_decoder(pCodecParameters->codec_id);
    AVCodecContext *pCodecContext = pFormatContext->streams[videoIndex]->codec;

    if (pCodec == NULL) {
        cout << "Code not found." << endl;
        return -1;
    }

    if (avcodec_open2(pCodecContext, pCodec, NULL) < 0) {
        cout << "Could not open codec" << endl;
        return -1;
    }

    AVPacket *pPacket = (AVPacket *) av_malloc(sizeof(AVPacket));

    AVCodec *pngCodec = avcodec_find_encoder(AV_CODEC_ID_PNG);

    if (!pngCodec) {
        printf("avcodec_find_decoder() failed to find encoder\n");
        return -1;
    }

    AVCodecContext *pngCodecContext = avcodec_alloc_context3(pngCodec);
    pngCodecContext->bit_rate = pCodecParameters->bit_rate;
    pngCodecContext->width = pCodecParameters->width;
    pngCodecContext->height = pCodecParameters->height;
    pngCodecContext->pix_fmt = AV_PIX_FMT_RGBA;
    pngCodecContext->codec_type = AVMEDIA_TYPE_VIDEO;
    pngCodecContext->time_base.num = pFormatContext->streams[videoIndex]->time_base.num;
    pngCodecContext->time_base.den = pFormatContext->streams[videoIndex]->time_base.den;

    if (avcodec_open2(pngCodecContext, pngCodec, NULL) < 0) {
        printf("avcodec_open2() failed\n");
    }

    SwsContext *pngSwsContext = sws_getContext(pCodecParameters->width,
                                               pCodecParameters->height,
                                               (AVPixelFormat) pCodecParameters->format,
                                               pCodecParameters->width,
                                               pCodecParameters->height,
                                               AV_PIX_FMT_RGBA,
                                               SWS_BILINEAR,
                                               NULL,
                                               NULL, NULL);

    AVFrame *pngFrame = av_frame_alloc();
    uint8_t *pngBuffer = (uint8_t *) av_malloc(
            (size_t) av_image_get_buffer_size(AV_PIX_FMT_RGBA, pngCodecContext->width, pngCodecContext->height, 1));
    pngFrame->format = AV_PIX_FMT_RGBA;
    pngFrame->width = pngCodecContext->width;
    pngFrame->height = pngCodecContext->height;
    av_image_fill_arrays(pngFrame->data, pngFrame->linesize, pngBuffer, AV_PIX_FMT_RGBA, pngCodecContext->width,
                         pngCodecContext->height, 1);

    while (av_read_frame(pFormatContext, pPacket) >= 0) {

        if (pPacket->stream_index == videoIndex) {
            ret = avcodec_decode_video2(pCodecContext, pFrame, &gotPicture, pPacket);
            if (ret < 0) {
                cout << "Decode Error." << endl;
                return 0;
            }

            // 变换图像
            if (gotPicture) {
                if (pPacket->data) {
                    av_packet_unref(pPacket);
                }
                sws_scale(pngSwsContext,
                          (const uint8_t *const *) pFrame->data,
                          pFrame->linesize,
                          0,
                          pFrame->height,
                          pngFrame->data,
                          pngFrame->linesize);

                ret = avcodec_send_frame(pngCodecContext, pngFrame);
                if (ret < 0) {
                    cout << "send error frame" << endl;
                    continue;
                }
                ret = avcodec_receive_packet(pngCodecContext, pPacket);
                if (ret < 0) {
                    cout << "receive packet" << endl;
                    continue;
                }

                char *filename = "/Users/biezhihua/Desktop/one.png";
                FILE *picture = fopen(filename, "wb");
                fwrite(pPacket->data, pPacket->size, 1, picture);
                fclose(picture);
                break;
            }

        }
        av_packet_unref(pPacket);
    }


    sws_freeContext(pngSwsContext);
    av_frame_free(&pngFrame);
    av_frame_free(&pFrame);
    avcodec_close(pCodecContext);
    avformat_close_input(&pFormatContext);
    free(pngBuffer);
    return 0;
}