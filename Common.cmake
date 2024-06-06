set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set(TOP_THIRDPARTY "${CMAKE_CURRENT_SOURCE_DIR}/3rd")
set(TOP_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
if (CMAKE_CL_64)
  set(TOP_PLATFORM x64)
else ()
  set(TOP_PLATFORM x86)
endif ()

if (UNIX)
	set(CMAKE_CXX_FLAGS "-Wl,-rpath=./")
	set(CMAKE_C_FLAGS "-Wl,-rpath=./")
elseif (MSVC)
	add_compile_options("/utf-8")
	add_compile_definitions(UNICODE _UNICODE)
endif ()

configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/version.h.in"
    "${CMAKE_BINARY_DIR}/include/top/config/version.h"
)
configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/config.h.in"
    "${CMAKE_BINARY_DIR}/include/top/config/config.h"
)
configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/include/top/config/path.h.in"
    "${CMAKE_BINARY_DIR}/include/top/config/path.h"
)
