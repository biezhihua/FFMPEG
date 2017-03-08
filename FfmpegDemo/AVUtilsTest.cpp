#include <iostream>
#include <fstream>

extern "C" {
#include<libavformat/avformat.h>
#include<libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}
using namespace std;


void test_log() {
    av_register_all();

    AVFormatContext *obj = NULL;
    obj = avformat_alloc_context();

    char buffer[10] = "1234";

    printf("====================================\n");
    av_log(NULL, AV_LOG_PANIC, "Panic: Something went really wrong and we will crash now.\n");
    av_log(NULL, AV_LOG_FATAL, "Fatal: Something went wrong and recovery is not possible.\n");
    av_log(NULL, AV_LOG_ERROR, "Error: Something went wrong and cannot losslessly be recovered.\n");
    av_log(NULL, AV_LOG_WARNING, "Warning: This may or may not lead to problems.\n");
    av_log(NULL, AV_LOG_INFO, "Info: Standard information.%s \n", buffer);
    av_log(NULL, AV_LOG_VERBOSE, "Verbose: Detailed information.\n");
    av_log(NULL, AV_LOG_DEBUG, "Debug: Stuff which is only useful for libav* developers.\n");
    printf("====================================\n");

    avformat_free_context(obj);
}

int main() {
    test_log();
    return 0;
}

