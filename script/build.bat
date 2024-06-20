@echo off

chcp 65001

set BUILD_TYPE=x64-relwithdebinfo

cmake --preset %BUILD_TYPE% ..
pushd ../out/build/%BUILD_TYPE%
cmake --build .
ctest
cpack
popd
