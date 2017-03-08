#include <stdio.h>
#include <libavformat/avformat.h>

#define USE_H264BSF 0

int main() {

    AVOutputFormat *ofmt_v = NULL;
    AVOutputFormat *ofmt_a = NULL;

    AVFormatContext *ifmt_ctx = NULL;
    AVFormatContext *ofmt_ctx_v = NULL;
    AVFormatContext *ofmt_ctx_a = NULL;

    AVPacket pkt;

    int ret, i;
    int videoIndex = -1;
    int audioIndex = -1;
    int frameIndex = 0;

    const char *in_filename = "";
    const char *out_filename_v = "";
    const char *out_filename_a = "";

    av_register_all();

    // Input
    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, NULL, NULL)) < 0) {
        printf("Could not open input file\n");
        goto end;
    }
    if ((ret = avformat_find_stream_info(&ifmt_ctx, NULL)) < 0) {
        printf("Failed to retrieve input stream information\n");
        goto end;
    }

    // Output
    avformat_alloc_output_context2(&ofmt_ctx_v, NULL, NULL, out_filename_v);
    if (!ofmt_ctx_v) {
        printf("Could not create output context\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }
    avformat_alloc_output_context2(&ofmt_ctx_a, NULL, NULL, out_filename_a);
    if (!ofmt_ctx_a) {
        printf("Could not create output context\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    ofmt_v = ofmt_ctx_v->oformat;

    ofmt_a = ofmt_ctx_a->oformat;

    for (i = 0; i < ifmt_ctx->nb_streams; ++i) {
        // Create output AVStream according to input AVStream
        AVFormatContext *ofmt_ctx;
        AVStream *in_stream = ifmt_ctx->streams[i];
        AVStream *out_stream = NULL;

        if (ifmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoIndex = i;
            out_stream = avformat_new_stream(ofmt_ctx_v, in_stream->codec->codec);
            ofmt_ctx = ofmt_ctx_v;
        } else if (ifmt_ctx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO) {
            audioIndex = i;
            out_stream = avformat_new_stream(ofmt_ctx_a, in_stream->codec->codec);
            ofmt_ctx = ofmt_ctx_a;
        } else {
            break;
        }

        if (!out_stream) {
            printf("Failed allocating output stream\n");
            ret = AVERROR_UNKNOWN;
            goto end;
        }

        if (avcodec_copy_context(out_stream->codec, in_stream->codec) < 0) {
            printf("Failed to copy context from input to output stream codec context\n");
            goto end;
        }

        out_stream->codec->codec_tag = 0;
        if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER) {
            out_stream->codec->flags |= CODEC_FLAG_GLOBAL_HEADER;
        }
    }

    printf("\n==============Input Video=============\n");
    av_dump_format(ifmt_ctx, 0, in_filename, 0);
    printf("\n==============Output Video============\n");
    av_dump_format(ofmt_ctx_v, 0, out_filename_v, 1);
    printf("\n==============Output Audio============\n");
    av_dump_format(ofmt_ctx_a, 0, out_filename_a, 1);

    end:
    avformat_close_input(&ifmt_ctx);

    if (ofmt_ctx_a && !(ofmt_a->flags & AVFMT_NOFILE)) {
        avio_close(ofmt_ctx_a->pb);
    }

    if (ofmt_ctx_v && !(ofmt_v->flags & AVFMT_NOFILE)) {
        avio_close(ofmt_ctx_v->pb);
    }

    avformat_free_context(ofmt_ctx_a);
    avformat_free_context(ofmt_ctx_v);

    if (ret < 0 && ret != AVERROR_EOF) {
        printf( "Error occurred.\n");
        return -1;
    }
    return 0;
}