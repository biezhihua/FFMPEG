#!/bin/bash

FFMPEG_VERSION="3.1.4"

FFMPEG_BUILD_DIR=`pwd`/ffmpeg-build

# -e 判断文件是否存在
if [ ! -e "ffmpeg-${FFMPEG_VERSION}.tar.bz2" ]; then
    echo "Dowloading ffmpeg-${FFMPEG_VERSION}.tar.bz2"
    ## 下载 -O以网络名作为文件名 -L强制重定向
    curl -LO http://ffmpeg.org/releases/ffmpeg-${FFMPEG_VERSION}.tar.bz2
else
    echo "Using ffmpeg-${FFMPEG_VERSION}.tar.bz2"
fi

if [ ! -d "ffmpeg-${FFMPEG_VERSION}" ]; then
    echo "Decompressioning ..."
    ## 解压ffmpeg-3.1.4.tar.bz2文件
    tar -xvf ffmpeg-${FFMPEG_VERSION}.tar.bz2
else
    echo "ffmpeg-${FFMPEG_VERSION} exist"
fi

function buildFFmpeg {

    if [ ! -d ${FFMPEG_BUILD_DIR} ]; then
        mkdir ${FFMPEG_BUILD_DIR}
    fi

    pushd ffmpeg-${FFMPEG_VERSION}
     ./configure  --prefix=${FFMPEG_BUILD_DIR} \
        --enable-shared \
        --enable-small \
        --disable-ffplay \
        --disable-ffmpeg \
        --disable-ffprobe \
        --disable-avfilter \
        --disable-avdevice \
        --disable-ffserver \
        --disable-doc \
        --disable-avdevice \
        --disable-swresample \
        --disable-postproc \
        --disable-avfilter \
        --disable-gpl \
        --disable-encoders \
        --disable-hwaccels \
        --disable-muxers \
        --disable-bsfs \
        --disable-protocols \
        --disable-indevs \
        --disable-outdevs \
        --disable-devices \
        --disable-filters \
        --enable-encoder=png \
        --enable-protocol=file,http,https,mmsh,mmst,pipe,rtmp,rtmps,rtmpt,rtmpts,rtp \
        --disable-debug \
        --disable-asm

     make clean
     make -j8 install
    popd

    ## copy the binaries

}

buildFFmpeg

