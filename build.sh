#!/bin/bash
# Inspired by https://github.com/marcothelost/ceremonial-robes/blob/main/build.sh

BUILD_DIR="build"

if [[ "$*" == *"--windows"* ]]; then
    echo "=== Windows Build ==="
    BUILD_FOR_WINDOWS="ON"
else
    echo "=== Linux Build ==="
    BUILD_FOR_WINDOWS="OFF"
fi

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake .. -DBUILD_FOR_WINDOWS=$BUILD_FOR_WINDOWS
cmake --build .

if [[ "$*" == *"--run"* ]]; then
    echo "=== Executing Game ==="
    if [ $BUILD_FOR_WINDOWS == "ON" ]; then
        wine ./game.exe &
    else
        ./game &
    fi
fi