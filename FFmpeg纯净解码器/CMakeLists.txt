cmake_minimum_required(VERSION 3.7)
project(FFmpeg)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

set(SOURCE_FILES main.c)
add_executable(FFmpeg ${SOURCE_FILES})

target_link_libraries(
        FFmpeg
        avcodec
        avdevice
        avfilter
        avformat
        avresample
        avutil
        postproc
        swresample
        swscale
        ${}
)