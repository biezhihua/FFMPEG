#include <stdio.h>
#include "libavutil/log.h"
#include "libavformat/avformat.h"

#define Test(x,y) (x##y)

void fun(int a, ...) {
    va_list pp;
    va_start(pp, a);
    do {
        printf("Param = %d \n", a);
        a = va_arg(pp, int);
    } while (a != 0);
}

void my_logoutput(void *ptr, int level, const char *fmt, va_list vl) {
    FILE *fp = fopen("../my_log.txt", "a+");
    if (fp) {
        vfprintf(fp, fmt, vl);
        fflush(fp);
        fclose(fp);
    }
}


int main() {
    av_log(NULL, AV_LOG_INFO, "%d\n", Test(123, 456));

    fun(20, 40, 60, 80, 0);

    // av_log_set_callback(my_logoutput);

    av_register_all();
    AVFormatContext *fc = avformat_alloc_context();

    int log = av_log_get_level();
    av_log(NULL, AV_LOG_INFO, "%d\n", log);

    av_log(NULL, AV_LOG_INFO, "Hello World\n");

    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "Hello World\n");

    av_log_set_level(AV_LOG_ERROR);
    av_log(NULL, AV_LOG_ERROR, "Hello World\n");

    printf("\033[33m Hello World. \033[0m \n");


    return 0;
}