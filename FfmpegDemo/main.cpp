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

    // 封装格式上下文结构体，保存视频文件、封装、格式相关信息
    AVFormatContext *pFormatContext;
    int i;
    int videoIndex = -1;
    int subtitleIndex = -1;
    // 解码器结构体，保存了视频、音频解码相关信息
    AVCodecContext *pCodecContext;
    AVCodecParameters *pCodecParameters;
    // 每一种视频、音频解码器（H.264）对应一个结构体
    AVCodec *pCodec;
    //
    AVSubtitle *pSubtitle;
    // 存储一帧解码后的数据
    AVFrame *pFrame;
    AVFrame *pFrameYUV;
    uint8_t *outBuffer;
    // 存储一帧压缩编码数据
    AVPacket *pPacket;
    int ySize;
    int ret;
    int gotPicture;
    struct SwsContext *imgConvertContext;
    char filePath[] = "/Users/biezhihua/Downloads/biezhihua.mp4";


    // 注册所有组件
    av_register_all();

    // 初始化全局网络组件
    avformat_network_init();

    // 获取格式上下文信息
    pFormatContext = avformat_alloc_context();

    // 打开视频、音频文件
    if (avformat_open_input(&pFormatContext, filePath, NULL, NULL) != 0) {
        cout << "Couldn't open input stream" << endl;
        return -1;
    }

    // 输出文件信息
    av_dump_format(pFormatContext, 0, filePath, 0);

    // 获取文件格式信息
    if (avformat_find_stream_info(pFormatContext, NULL) < 0) {
        cout << "Couldn't find stream information." << endl;
        return -1;
    }

    //  获取视频流索引
    for (int i = 0; i < pFormatContext->nb_streams; ++i) {
        if (pFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
            cout << "Video Index " << videoIndex << endl;
        } else if (pFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_SUBTITLE) {
            subtitleIndex = i;
            cout << "Subtitle Index " << subtitleIndex << endl;
        }
    }

    //  判断索引是否合法
    if (videoIndex == -1) {
        cout << "Don't find a video stream." << endl;
        return -1;
    }

    if (subtitleIndex == -1) {
        cout << "Don't find a subtitle stream." << endl;
        return -1;
    }

    subtitleIndex = 2;

    // 获取解码参数
    pCodecContext = pFormatContext->streams[subtitleIndex]->codec;
    pCodecParameters = pFormatContext->streams[subtitleIndex]->codecpar;

    // 获取解码器
    pCodec = avcodec_find_decoder(pCodecParameters->codec_id);

    if (pCodec == NULL) {
        cout << "Code not found." << endl;
        return -1;
    }

    // 使用解码器初始化解码上下文
    if (avcodec_open2(pCodecContext, pCodec, NULL) < 0) {
        cout << "Could not open codec" << endl;
        return -1;
    }


    //
    pSubtitle = (AVSubtitle *) av_malloc(sizeof(AVSubtitle));
    // 分配帧空间
    pFrame = av_frame_alloc();
    // 分配YUV帧空间
    pFrameYUV = av_frame_alloc();
    // 分配输出缓存
    outBuffer = (uint8_t *) av_malloc(
            avpicture_get_size(AV_PIX_FMT_YUV420P, pCodecParameters->width, pCodecParameters->height));
    // 填充YUV
    avpicture_fill((AVPicture *) pFrameYUV, outBuffer, AV_PIX_FMT_YUV420P, pCodecParameters->width,
                   pCodecParameters->height);
    // H.264数据包
    pPacket = (AVPacket *) av_malloc(sizeof(AVPacket));

    // 获取图像转换的上下文
    imgConvertContext = sws_getContext(pCodecContext->width, pCodecContext->height, pCodecContext->pix_fmt,
                                       pCodecContext->width, pCodecContext->height, AV_PIX_FMT_YUV420P, SWS_BICUBIC,
                                       NULL, NULL, NULL);

    int count = 0;
    while (av_read_frame(pFormatContext, pPacket) >= 0) {
        // 如果H.264包是视频
//        if (pPacket->stream_index == videoIndex) {
//
//            // 解码成YUV
//            ret = avcodec_decode_video2(pCodecContext, pFrame, &gotPicture, pPacket);
//            if (ret < 0) {
//                cout << "Decode Error." << endl;
//                return 0;
//            }
//
//            // 变换图像
//            if (gotPicture) {
//                sws_scale(imgConvertContext, (const uint8_t *const *) pFrame->data, pFrame->linesize, 0,
//                          pCodecContext->height, pFrameYUV->data, pFrameYUV->linesize);
//            }
//        }

        if (pPacket->stream_index == subtitleIndex) {
            count++;
            ret = avcodec_decode_subtitle2(pCodecContext, pSubtitle, &gotPicture, pPacket);
            if (ret < 0) {
                cout << "Decode Error." << endl;
                return 0;
            }
            if (pSubtitle->num_rects > 0) {
//                cout << "linesize "<< pSubtitle->rects[0]->linesize[0] << " " <<  pSubtitle->rects[0]->linesize[1] << " " << pSubtitle->rects[0]->linesize[2] << " " <<  pSubtitle->rects[0]->linesize[3] << endl;
                if (pSubtitle->rects[0]->data != NULL) {
                    cout << "data " << count << " " << pSubtitle->rects[0]->data[0] <<
                         endl;
                }
            }

        }

        av_packet_unref(pPacket);
    }


    sws_freeContext(imgConvertContext);
    av_frame_free(&pFrameYUV);
    av_frame_free(&pFrame);
    avcodec_close(pCodecContext);
    avformat_close_input(&pFormatContext);

    cout << "End";
    return 0;
}