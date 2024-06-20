@echo off

chcp 65001

set BUILD_TYPE=x64-relwithdebinfo
call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat"

cmake --preset %BUILD_TYPE% ..
cd ../out/build/%BUILD_TYPE%
cmake --build .
ctest
cpack
