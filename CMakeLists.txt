cmake_minimum_required(VERSION 3.12)

project(Top VERSION 1.0.0)

include(Common.cmake)
include(ThirdParty.cmake)
include(Pack.cmake)

add_subdirectory(src/main)
add_subdirectory(src/qmain)
add_subdirectory(src/app)
