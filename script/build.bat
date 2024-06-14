@echo off

cmake --preset x64-relwithdebinfo ..
cmake --build .
ctest
cpack
