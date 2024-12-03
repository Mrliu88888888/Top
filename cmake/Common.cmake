set(TOP_THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty")
set(TOP_BINARY_INCLUDE "${CMAKE_BINARY_DIR}/include")
set(TOP_THIRDPARTY_OUT_DIRS "${CMAKE_BINARY_DIR}/3rd")
if(CMAKE_CL_64)
	set(TOP_ARCH "x64")
else()
	set(TOP_ARCH "x86")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(TOP_DEBUG TRUE)
	set(TOP_DEBUG_LIB_SUFFIX "d")
	set(TOP_BUILD_TYPE "debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	set(TOP_DEBUG FALSE)
	set(TOP_DEBUG_LIB_SUFFIX)
	set(TOP_BUILD_TYPE "relwithdebinfo")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(TOP_DEBUG FALSE)
	set(TOP_DEBUG_LIB_SUFFIX)
	set(TOP_BUILD_TYPE "release")
endif()
if(WIN32)
	set(TOP_PLATFORM "windows")
elseif(UNIX)
	set(TOP_PLATFORM "linux")
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(TOP_DEBUG)
	add_compile_definitions(_DEBUG)
endif()
if(UNIX)
	set(CMAKE_C_FLAGS "-Wl,-rpath=./")
	set(CMAKE_CXX_FLAGS "-Wl,-rpath=./")
elseif(MSVC)
	add_compile_options("/utf-8")
endif()
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(ARCHIVE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/version.h.in"
	"${TOP_BINARY_INCLUDE}/${PROJECT_NAME}/config/version.h"
)
configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/config.h.in"
	"${TOP_BINARY_INCLUDE}/${PROJECT_NAME}/config/config.h"
)
configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/global.h"
	"${TOP_BINARY_INCLUDE}/${PROJECT_NAME}/global.h"
)
