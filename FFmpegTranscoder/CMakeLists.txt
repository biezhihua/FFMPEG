cmake_minimum_required(VERSION 3.6)
project(FFmpegTranscoder)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

set(SOURCE_FILES main.c)
add_executable(FFmpegTranscoder ${SOURCE_FILES})

target_link_libraries(
        FFmpegTranscoder
        avcodec
        avdevice
        avfilter
        avformat
        avresample
        avutil
        postproc
        swresample
        swscale
)