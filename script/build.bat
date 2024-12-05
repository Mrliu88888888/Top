@echo off

chcp 65001

set BUILD_TYPE="%~1"

if %BUILD_TYPE%=="" (
	set BUILD_TYPE="x64-relwithdebinfo"
)

echo BUILD_TYPE: %BUILD_TYPE%

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat"

cmake --preset %BUILD_TYPE% ..
cd ../out/build/%BUILD_TYPE%
cmake --build .
ctest
cpack
