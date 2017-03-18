cmake_minimum_required(VERSION 3.6)
project(FFmpegAVFilter)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

include_directories(/usr/local/Cellar/sdl2/2.0.5/include/)
link_directories(/usr/local/Cellar/sdl2/2.0.5/lib/)

set(SOURCE_FILES main.c)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY})

add_executable(FFmpegAVFilter ${SOURCE_FILES})

target_link_libraries(
        FFmpegAVFilter
        avcodec
        avdevice
        avfilter
        avformat
        avresample
        avutil
        postproc
        swresample
        swscale
        ${SDL2_LIBRARY}
)