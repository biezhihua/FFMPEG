#include <stdio.h>
#include "libavcodec/avcodec.h"

int main() {

    AVCodec *pCodec;
    AVCodecContext *pCodecCtx = NULL;
    AVCodecParserContext *pCodecParseCtx = NULL;

    FILE *fp_in;
    FILE *fp_out;

    AVFrame *pFrame;

    const int in_buffer_size = 4096;
    uint8_t in_buffer[in_buffer_size + FF_INPUT_BUFFER_PADDING_SIZE] = {0};
    uint8_t *cur_ptr;
    int cur_size;
    AVPacket packet;
    int ret, got_picture;
    int y_size;

#if TEST_HEVC
    enum AVCodecID codec_id=AV_CODEC_ID_HEVC;
    char filepath_in[]="bigbuckbunny_480x272.hevc";
#elif TEST_H264
    AVCodecID codec_id=AV_CODEC_ID_H264;
    char filepath_in[]="bigbuckbunny_480x272.h264";
#else
    enum AVCodecID codec_id = AV_CODEC_ID_MPEG2VIDEO;
    char filepath_in[] = "bigbuckbunny_480x272.m2v";
#endif

    char filepath_out[] = "bigbuckbunny_480x272.yuv";
    int first_time = 1;

    avcodec_register_all();
    pCodec = avcodec_find_decoder(codec_id);
    if (!pCodec) {
        printf("Codec not found\n");
        return -1;
    }

    pCodecCtx = avcodec_alloc_context3(pCodec);
    if (!pCodecCtx) {
        printf("Could not allocate video codec context\n");
        return -1;
    }

    pCodecParseCtx = av_parser_init(codec_id);
    if (!pCodecParseCtx) {
        printf("Could not allocate video parser context\n");
        return -1;
    }

    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
        printf("Could not open codec\n");
        return -1;
    }

    fp_in = fopen(filepath_in, "rb");
    if (!fp_in) {
        printf("Could not open input stream\n");
        return -1;
    }

    //Output File
    fp_out = fopen(filepath_out, "wb");
    if (!fp_out) {
        printf("Could not open output YUV file\n");
        return -1;
    }

    pFrame = av_frame_alloc();
    av_init_packet(&packet);

    while (1) {
        cur_size = fread(in_buffer, 1, in_buffer_size, fp_in);
        if (cur_size == 0) {
            break;
        }
        cur_ptr = in_buffer;

        while (cur_size > 0) {
            int len = av_parser_parse2(
                    pCodecParseCtx, pCodecCtx,
                    &packet.data, &packet.size,
                    cur_ptr, cur_size,
                    AV_NOPTS_VALUE, AV_NOPTS_VALUE, AV_NOPTS_VALUE
            );

            cur_ptr += len;
            cur_size -= len;

            if (packet.side_data == 0) {
                continue;
            }

            printf("[Packet]Size:%6d\t", packet.size);
            switch (pCodecParseCtx->pict_type) {
                case AV_PICTURE_TYPE_I:
                    printf("Type:I\t");
                    break;
                case AV_PICTURE_TYPE_P:
                    printf("Type:P\t");
                    break;
                case AV_PICTURE_TYPE_B:
                    printf("Type:B\t");
                    break;
                default:
                    printf("Type:Other\t");
                    break;
            }
            printf("Number:%4d\n", pCodecParseCtx->output_picture_number);

            ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, &packet);
            if (ret < 0) {
                printf("Decode Error. \n");
                return ret;
            }

            if (got_picture) {
                if (first_time) {
                    printf("\nCodec Full Name:%s\n", pCodecCtx->codec->long_name);
                    printf("width:%d\nheight:%d\n\n", pCodecCtx->width, pCodecCtx->height);
                    first_time = 0;
                }
                //Y, U, V
                for (int i = 0; i < pFrame->height; i++) {
                    fwrite(pFrame->data[0] + pFrame->linesize[0] * i, 1, pFrame->width, fp_out);
                }
                for (int i = 0; i < pFrame->height / 2; i++) {
                    fwrite(pFrame->data[1] + pFrame->linesize[1] * i, 1, pFrame->width / 2, fp_out);
                }
                for (int i = 0; i < pFrame->height / 2; i++) {
                    fwrite(pFrame->data[2] + pFrame->linesize[2] * i, 1, pFrame->width / 2, fp_out);
                }

                printf("Succeed to decode 1 frame!\n");
            }
        }
    }

    // Flush Deocder
    packet.data = NULL;
    packet.size = 0;
    while (1) {
        ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, &packet);
        if (ret < 0) {
            printf("Decode Error.\n");
            return ret;
        }

        if (!got_picture) {
            break;
        } else {
            //Y, U, V
            for (int i = 0; i < pFrame->height; i++) {
                fwrite(pFrame->data[0] + pFrame->linesize[0] * i, 1, pFrame->width, fp_out);
            }
            for (int i = 0; i < pFrame->height / 2; i++) {
                fwrite(pFrame->data[1] + pFrame->linesize[1] * i, 1, pFrame->width / 2, fp_out);
            }
            for (int i = 0; i < pFrame->height / 2; i++) {
                fwrite(pFrame->data[2] + pFrame->linesize[2] * i, 1, pFrame->width / 2, fp_out);
            }

            printf("Flush Decoder: Succeed to decode 1 frame!\n");
        }
    }

    fclose(fp_in);
    fclose(fp_out);


    av_parser_close(pCodecParseCtx);

    av_frame_free(&pFrame);
    avcodec_close(pCodecCtx);
    av_free(pCodecCtx);


    return 0;
}