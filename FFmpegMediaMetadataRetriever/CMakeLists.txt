cmake_minimum_required(VERSION 3.6)
project(NativeMediaMetadataRetrieverDemo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

set(SOURCE_FILES main.cpp ffmpeg_utils.h ffmpeg_utils.c ffmpeg_mediametadataretriever.c ffmpeg_mediametadataretriever.h)

add_executable(NativeMediaMetadataRetrieverDemo ${SOURCE_FILES})

target_link_libraries(
        NativeMediaMetadataRetrieverDemo
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
