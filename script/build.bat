@echo off

chcp 65001

set BUILD_TYPE="%~1"
set BUILD_SHARED_LIB="%~2"

if %BUILD_TYPE%=="" (
	set BUILD_TYPE="x64-relwithdebinfo"
)
if %BUILD_SHARED_LIB%=="" (
	set BUILD_SHARED_LIB="ON"
)

echo BUILD_TYPE: %BUILD_TYPE%
echo BUILD_SHARED_LIB: %BUILD_SHARED_LIB%

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat"

cmake --preset %BUILD_TYPE% .. -DBUILD_SHARED_LIBS=%BUILD_SHARED_LIB%
cd ../out/build/%BUILD_TYPE%
cmake --build .
ctest
cpack
