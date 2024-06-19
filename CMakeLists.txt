cmake_minimum_required(VERSION 3.12)

project(Top VERSION 1.0.0)

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/ThirdParty.cmake)

option(BUILD_TESTING "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(src)

if (${BUILD_TESTING})
	enable_testing()
	add_subdirectory(test)
endif ()
if (${BUILD_EXAMPLES})
	add_subdirectory(example)
endif ()



install(FILES
	cmake/TopConfig.cmake

	DESTINATION share/${PROJECT_NAME}
)

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
