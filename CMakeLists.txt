cmake_minimum_required(VERSION 3.12)

project(Top VERSION 1.0.0)

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/ThirdParty.cmake)
include(cmake/util/FindDependencies.cmake)

option(BUILD_TESTING "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)
option(BUILD_PROJ_SQLITERPC "build SQLiteRPC" ON)
option(BUILD_PROJ_VIDEOCAMERA "build VideoCamera" ON)

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

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build examples: ${BUILD_EXAMPLES}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "${PROJECT_NAME} build SQLiteRPC: ${BUILD_PROJ_SQLITERPC}")
message(STATUS "${PROJECT_NAME} build VideoCamera: ${BUILD_PROJ_VIDEOCAMERA}")
