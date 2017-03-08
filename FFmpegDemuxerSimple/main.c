#include <stdio.h>
#include <libavformat/avformat.h>

#define USE_H264BSF 1

int main() {

    AVFormatContext *ifmt_ctx = NULL;
    AVPacket pkt;
    int ret, i;
    int videoIndex = -1;
    int audioIndex = -1;

    const char *in_filename = "/Users/biezhihua/workspace/Videos/biezhihua.mp4";
    const char *out_filename_v = "../test.h264";
    const char *out_filename_a = "../test.aac";

    av_register_all();

    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, 0, 0)) < 0) {
        printf("Could not open input file");
        return -1;
    }

    if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0) {
        printf("Failed to retrieve input stream information");
        return -1;
    }

    for (i = 0; i < ifmt_ctx->nb_streams; ++i) {
        if (ifmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
        } else if (ifmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            audioIndex = i;
        }
    }

    av_dump_format(ifmt_ctx, 0, in_filename, 0);

    FILE *fp_video = fopen(out_filename_v, "wb+");
    FILE *fp_audio = fopen(out_filename_a, "wb+");

#if USE_H264BSF
    AVBitStreamFilterContext *h264bsfc = av_bitstream_filter_init("h264_mp4toannexb");
#endif

    while (av_read_frame(ifmt_ctx, &pkt) >= 0) {
        if (pkt.stream_index == videoIndex) {
#if  USE_H264BSF
            av_bitstream_filter_filter(h264bsfc, ifmt_ctx->streams[videoIndex]->codec, NULL,
                                       &pkt.data, &pkt.size, pkt.data, pkt.size, 0);
#endif
            printf("Write Video Packet. Size:%d\tpts:%11lld\n", pkt.size, pkt.pts);
            fwrite(pkt.data, 1, pkt.size, fp_video);
        } else if (pkt.stream_index == audioIndex) {
            /**
             * AAC in some container format (FLV,MP4,MKV etc.)
             * need to add 7 bytes ADTS Header in front of AVPacket data manually.
             * Other Audio Codec(MP3) works well.
             */
            printf("Write Audio Packet. Size:%d\tpts:%11lld\n", pkt.size, pkt.pts);
            fwrite(pkt.data, 1, pkt.size, fp_audio);
        }
        av_packet_unref(&pkt);
    }

#if  USE_H264BSF
    av_bitstream_filter_close(h264bsfc);
#endif

    fclose(fp_video);
    fclose(fp_audio);

    avformat_close_input(&ifmt_ctx);

    if (ret < 0 && ret != AVERROR_EOF) {
        printf("Error occurred.\n");
        return -1;
    }
    return 0;
}