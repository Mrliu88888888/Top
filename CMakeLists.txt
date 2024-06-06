cmake_minimum_required(VERSION 3.12)

project(Top VERSION 1.0.0)

include(Common.cmake)
include(ThirdParty.cmake)
include(Pack.cmake)

option(BUILD_TESTING "test" ON)

add_subdirectory(src/main)
add_subdirectory(src/qmain)
add_subdirectory(src/app)
add_subdirectory(src/conv)

if (${BUILD_TESTING})
	add_subdirectory(test)
endif ()
