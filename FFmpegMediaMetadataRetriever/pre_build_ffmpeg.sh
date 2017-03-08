#!/bin/bash

export WORKING_DIR=`pwd`

FFMPEG_DIR=$WORKING_DIR/ffmpeg

export NDK='/Users/biezhihua/Library/Android/sdk/ndk-bundle'


if [ "$NDK" = "" ] || [ ! -d $NDK ]; then
    echo "NDK variable not set or path to NDK is invalid, exiting..."
	exit 1
fi

echo "NDK DIR: $NDK"

if [ ! -d $FFMPEG_DIR ]; then
    cd $WORKING_DIR
    echo "FFMPEG_DIR : $FFMPEG_DIR"


fi


echo Native build complete, exiting...
exit
