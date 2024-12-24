set(TOP_THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty")
set(TOP_BINARY_INCLUDE "${CMAKE_BINARY_DIR}/include")
set(TOP_THIRDPARTY_OUT_DIRS "${CMAKE_BINARY_DIR}/3rd")
if(CMAKE_CL_64)
	set(TOP_SYSTEM_BITNESS "x64")
else()
	set(TOP_SYSTEM_BITNESS "x86")
endif()
if(WIN32)
	set(TOP_OS_PLATFORM "windows")
elseif(UNIX)
	set(TOP_OS_PLATFORM "linux")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(TOP_DEBUG TRUE)
else()
	set(TOP_DEBUG FALSE)
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(TOP_DEBUG)
	add_compile_definitions(_DEBUG)
endif()
if(UNIX)
	set(CMAKE_C_FLAGS "-Wl,-rpath=./:./lib")
	set(CMAKE_CXX_FLAGS "-Wl,-rpath=./:./lib")
elseif(MSVC)
	add_compile_options("/utf-8")
	add_compile_definitions(_UNICODE UNICODE)
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
