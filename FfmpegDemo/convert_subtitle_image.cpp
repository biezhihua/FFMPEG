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
    int subtitleIndex = -1;
    int gotPicture;
    char filePath[] = "/Users/biezhihua/workspace/Videos/biezhihua1.mkv";

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


    subtitleIndex = 2;

    AVSubtitle *pSubtitle = (AVSubtitle *) av_malloc(sizeof(AVSubtitle));

//    AVCodecParameters *pCodecParameters = pFormatContext->streams[videoIndex]->codecpar;
//    AVCodec *pCodec = avcodec_find_decoder(pCodecParameters->codec_id);
//    AVCodecContext *pCodecContext = pFormatContext->streams[videoIndex]->codec;

    AVCodecParameters *pSubtitleCodecParameters = pFormatContext->streams[subtitleIndex]->codecpar;
    AVCodec *pSubtitleCodec = avcodec_find_decoder(pSubtitleCodecParameters->codec_id);
    AVCodecContext *pSubtitleCodecContext = pFormatContext->streams[subtitleIndex]->codec;

//    if (pCodec == NULL || pSubtitleCodec == NULL) {
//        cout << "Code not found." << endl;
//        return -1;
//    }

//    if (avcodec_open2(pCodecContext, pCodec, NULL) < 0) {
//        cout << "Could not open codec" << endl;
//        return -1;
//    }

    if (avcodec_open2(pSubtitleCodecContext, pSubtitleCodec, NULL) < 0) {
        cout << "Could not open codec" << endl;
        return -1;
    }

    AVPacket *pPacket = (AVPacket *) av_malloc(sizeof(AVPacket));

    AVCodec *pngCodec = avcodec_find_encoder(AV_CODEC_ID_PNG);

    if (!pngCodec) {
        printf("avcodec_find_decoder() failed to find encoder\n");
        return -1;
    }

//    AVCodecContext *pngCodecContext = avcodec_alloc_context3(pngCodec);
//    pngCodecContext->bit_rate = pCodecParameters->bit_rate;
//    pngCodecContext->width = pCodecParameters->width;
//    pngCodecContext->height = pCodecParameters->height;
//    pngCodecContext->pix_fmt = AV_PIX_FMT_RGBA;
//    pngCodecContext->codec_type = AVMEDIA_TYPE_VIDEO;
//    pngCodecContext->time_base.num = pFormatContext->streams[videoIndex]->time_base.num;
//    pngCodecContext->time_base.den = pFormatContext->streams[videoIndex]->time_base.den;

//    if (avcodec_open2(pngCodecContext, pngCodec, NULL) < 0) {
//        printf("avcodec_open2() failed\n");
//    }
//
//    AVFrame *pngFrame = av_frame_alloc();
//    uint8_t *pngBuffer = (uint8_t *) av_malloc(
//            (size_t) av_image_get_buffer_size(AV_PIX_FMT_RGBA, pngCodecContext->width, pngCodecContext->height, 1));
//    pngFrame->format = AV_PIX_FMT_RGBA;
//    pngFrame->width = pngCodecContext->width;
//    pngFrame->height = pngCodecContext->height;
//    av_image_fill_arrays(pngFrame->data, pngFrame->linesize, pngBuffer, AV_PIX_FMT_RGBA, pngCodecContext->width,
//                         pngCodecContext->height, 1);

    while (av_read_frame(pFormatContext, pPacket) >= 0) {

        if (pPacket->stream_index == subtitleIndex) {
            ret = avcodec_decode_subtitle2(pSubtitleCodecContext, pSubtitle, &gotPicture, pPacket);
            if (ret < 0) {
                cout << "Decode Error." << endl;
                return 0;
            }

            if (pSubtitle->num_rects > 0) {
                // 变换图像
                if (gotPicture) {
                    if (pPacket->data) {
                        av_packet_unref(pPacket);
                    }

                    AVSubtitleRect *rect = pSubtitle->rects[0];
                    if (rect->data == NULL) {
                        continue;

                    }


//                    SwsContext *pngSwsContext = sws_getContext(rect->w,
//                                                               rect->h,
//                                                               (AVPixelFormat) pSubtitleCodecParameters->format,
//                                                               rect->w,
//                                                               rect->h,
//                                                               AV_PIX_FMT_RGBA,
//                                                               SWS_BILINEAR,
//                                                               NULL,
//                                                               NULL, NULL);
//
//                    AVCodecContext *pngCodecContext = avcodec_alloc_context3(pngCodec);
//                    pngCodecContext->width = rect->w;
//                    pngCodecContext->height = rect->h;
//                    pngCodecContext->pix_fmt = AV_PIX_FMT_RGBA;
//                    pngCodecContext->codec_type = AVMEDIA_TYPE_SUBTITLE;
//
//                    if (avcodec_open2(pngCodecContext, pngCodec, NULL) < 0) {
//                        printf("avcodec_open2() failed\n");
//                    }
//
//                    AVFrame *pngFrame = av_frame_alloc();
//                    uint8_t *pngBuffer = (uint8_t *) av_malloc((size_t) av_image_get_buffer_size(AV_PIX_FMT_RGBA, pngCodecContext->width, pngCodecContext->height, 1));
//                    pngFrame->format = AV_PIX_FMT_RGBA;
//                    pngFrame->width = pngCodecContext->width;
//                    pngFrame->height = pngCodecContext->height;
//                    av_image_fill_arrays(pngFrame->data, pngFrame->linesize, pngBuffer, AV_PIX_FMT_RGBA, pngCodecContext->width, pngCodecContext->height, 1);
//
//                    sws_scale(pngSwsContext,
//                              (const uint8_t *const *) pSubtitle->rects[0],
//                              pSubtitle->rects[0]->linesize,
//                              0,
//                              pSubtitle->rects[0]->h,
//                              pngFrame->data,
//                              pngFrame->linesize);
//
//                    sws_freeContext(pngSwsContext);
//
//                    ret = avcodec_send_frame(pngCodecContext, pngFrame);
//                    if (ret < 0) {
//                        cout << "send error frame" << endl;
//                        continue;
//                    }
//                    ret = avcodec_receive_packet(pngCodecContext, pPacket);
//                    if (ret < 0) {
//                        cout << "receive packet" << endl;
//                        continue;
//                    }
//
//                    char *filename = "/Users/biezhihua/Desktop/one.png";
//                    FILE *picture = fopen(filename, "wb");
//                    fwrite(pPacket->data, pPacket->size, 1, picture);
//                    fclose(picture);
                }

            }
        }
        av_packet_unref(pPacket);
    }

//    while (av_read_frame(pFormatContext, pPacket) >= 0) {
//
//        if (pPacket->stream_index == videoIndex) {
//            ret = avcodec_decode_video2(pCodecContext, pFrame, &gotPicture, pPacket);
//            if (ret < 0) {
//                cout << "Decode Error." << endl;
//                return 0;
//            }
//
//            // 变换图像
//            if (gotPicture) {
//                if (pPacket->data) {
//                    av_packet_unref(pPacket);
//                }
//                sws_scale(pngSwsContext,
//                          (const uint8_t *const *) pFrame->data,
//                          pFrame->linesize,
//                          0,
//                          pFrame->height,
//                          pngFrame->data,
//                          pngFrame->linesize);
//
//                ret = avcodec_send_frame(pngCodecContext, pngFrame);
//                if (ret < 0) {
//                    cout << "send error frame" << endl;
//                    continue;
//                }
//                ret = avcodec_receive_packet(pngCodecContext, pPacket);
//                if (ret < 0) {
//                    cout << "receive packet" << endl;
//                    continue;
//                }
//
//                char *filename = "/Users/biezhihua/Desktop/one.png";
//                FILE *picture = fopen(filename, "wb");
//                fwrite(pPacket->data, pPacket->size, 1, picture);
//                fclose(picture);
//                break;
//            }
//
//        }
//        av_packet_unref(pPacket);
//    }



    avformat_close_input(&pFormatContext);
    return 0;
}