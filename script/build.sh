#!/bin/bash

BUILD_TYPE=linux-debug

cmake --preset $BUILD_TYPE ..
cd ../out/build/$BUILD_TYPE
cmake --build .
ctest
cpack
