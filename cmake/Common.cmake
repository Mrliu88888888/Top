set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(UNIX)
	set(CMAKE_C_FLAGS "-Wl,-rpath=./")
	set(CMAKE_CXX_FLAGS "-Wl,-rpath=./")
elseif(MSVC)
	add_compile_options("/utf-8")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set(TOP_THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty")
set(TOP_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
if(CMAKE_CL_64)
  set(TOP_PLATFORM x64)
else()
  set(TOP_PLATFORM x86)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(TOP_DEBUG TRUE)
	set(TOP_DEBUG_LIB_SUFFIX "d")
else()
	set(TOP_DEBUG FALSE)
	set(TOP_DEBUG_LIB_SUFFIX)
endif()
if(WIN32)
	set(TOP_PLATFORM windows)
	set(TOP_LIB_PREFIX "")
	set(TOP_LIB_SUFFIX ".dll")
elseif(UNIX)
	set(TOP_PLATFORM linux)
	set(TOP_LIB_PREFIX "lib")
	set(TOP_LIB_SUFFIX ".so")
endif()

configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/version.h.in"
	"${CMAKE_BINARY_DIR}/include/top/config/version.h"
)
configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/config.h.in"
	"${CMAKE_BINARY_DIR}/include/top/config/config.h"
)
configure_file(
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/global.h"
	"${CMAKE_BINARY_DIR}/include/top/global.h"
)

install(DIRECTORY
	"${CMAKE_BINARY_DIR}/include"

	DESTINATION .
)
