cmake_minimum_required(VERSION 3.22)

option(BUILD_TESTING "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)
option(BUILD_PROJ_SQLITERPC "build SQLiteRPC" OFF)
option(BUILD_PROJ_VIDEOCAMERA "build VideoCamera" OFF)
option(USING_MIMALLOC "using mimalloc" OFF)

if(BUILD_TESTING)
	list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()
if(BUILD_PROJ_SQLITERPC)
	list(APPEND VCPKG_MANIFEST_FEATURES "sqliterpc")
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	list(APPEND VCPKG_MANIFEST_FEATURES "videocamera")
endif()
if(USING_MIMALLOC)
	list(APPEND VCPKG_MANIFEST_FEATURES "mimalloc")
endif()

project(Top VERSION 1.1.0)

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build examples: ${BUILD_EXAMPLES}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "${PROJECT_NAME} build SQLiteRPC: ${BUILD_PROJ_SQLITERPC}")
message(STATUS "${PROJECT_NAME} build VideoCamera: ${BUILD_PROJ_VIDEOCAMERA}")
message(STATUS "${PROJECT_NAME} using mimalloc: ${USING_MIMALLOC}")

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/ThirdParty.cmake)
include(cmake/Utils.cmake)

add_subdirectory(src)

if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(test)
endif()
if(BUILD_EXAMPLES)
	add_subdirectory(example)
endif()

install(DIRECTORY
	doc
	example

	DESTINATION ${CMAKE_INSTALL_PREFIX}
)
install(FILES
	README.md
	LICENSE

	DESTINATION ${CMAKE_INSTALL_PREFIX}
)
