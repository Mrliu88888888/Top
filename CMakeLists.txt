cmake_minimum_required(VERSION 3.22)

option(BUILD_TESTING "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)
option(USING_MIMALLOC "using mimalloc" OFF)

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build examples: ${BUILD_EXAMPLES}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "${PROJECT_NAME} using mimalloc: ${USING_MIMALLOC}")

if(BUILD_TESTING)
	list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()
if(BUILD_PROJ_SQLITERPC)
	list(APPEND VCPKG_MANIFEST_FEATURES "sqliterpc")
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	list(APPEND VCPKG_MANIFEST_FEATURES "videocamera")
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	list(APPEND VCPKG_MANIFEST_FEATURES "mimalloc")
endif()

project(Top VERSION 1.0.0)

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/ThirdParty.cmake)
if(WIN32)
	include(cmake/util/FindDependencies.cmake)
elseif(UNIX)
	include(cmake/util/CopyDependencies.cmake)
endif()

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

	DESTINATION .
)
install(FILES
	README.md
	LICENSE

	DESTINATION .
)
