cmake_minimum_required(VERSION 3.22)

option(BUILD_TESTING "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)

if(BUILD_TESTING)
	list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()

project(Top VERSION 1.0.0)

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build examples: ${BUILD_EXAMPLES}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/ThirdParty.cmake)

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
