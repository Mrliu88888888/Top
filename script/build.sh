#!/bin/bash

BUILD_TYPE=linux-relwithdebinfo

cmake --preset $BUILD_TYPE ..
cd ../out/build/$BUILD_TYPE
cmake --build .
cpack -G "TGZ"
cd -
