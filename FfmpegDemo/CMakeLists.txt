cmake_minimum_required(VERSION 3.6)
project(FfmpegDemo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

#include_directories(/Users/biezhihua/software/ffmpeg-3.2.4-builded/include/)
#link_directories(/Users/biezhihua/software/ffmpeg-3.2.4-builded/lib/)

set(SOURCE_FILES main.cpp)

add_executable(FfmpegDemo ${SOURCE_FILES})

target_link_libraries(
        FfmpegDemo
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
