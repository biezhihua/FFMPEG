cmake_minimum_required(VERSION 3.6)
project(Simple_ffmpeg_player)

set(CMAKE_CXX_STANDARD 11)

include_directories(/usr/local/Cellar/ffmpeg/3.1.4/include/)
link_directories(/usr/local/Cellar/ffmpeg/3.1.4/lib/)

include_directories(/usr/local/Cellar/sdl2/2.0.5/include/)
link_directories(/usr/local/Cellar/sdl2/2.0.5/lib/)

set(SOURCE_FILES main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIBRARY})

add_executable(Simple_ffmpeg_player ${SOURCE_FILES})

target_link_libraries(
        Simple_ffmpeg_player
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