cmake_minimum_required(VERSION 3.6)
project(FFmpegRemuxer)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

add_executable(FFmpegRemuxer ${SOURCE_FILES})

target_link_libraries(
        FFmpegRemuxer
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