cmake_minimum_required(VERSION 3.29)

option(BUILD_TESTING "build tests" ON)
option(BUILD_EXAMPLES "build examples" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)
option(USING_MIMALLOC "using mimalloc" OFF)

if(BUILD_TESTING)
	list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()
if(USING_MIMALLOC)
	list(APPEND VCPKG_MANIFEST_FEATURES "mimalloc")
endif()

project(Top VERSION 1.1.0)

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build examples: ${BUILD_EXAMPLES}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "${PROJECT_NAME} using mimalloc: ${USING_MIMALLOC}")

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/PackUtils.cmake)
include(cmake/ThirdParty.cmake)

install(DIRECTORY
	doc
	example

	DESTINATION .
)
install(FILES
	README.md
	LICENSE
	CHANGELOG.md

	DESTINATION .
)
install(DIRECTORY
	${EXECUTABLE_OUTPUT_PATH}/

	DESTINATION bin
	FILES_MATCHING
	PATTERN "*"
	PATTERN "*.exp" EXCLUDE
	PATTERN "*.ilk" EXCLUDE
	PATTERN "*.lib" EXCLUDE
	PATTERN "*.pdb" EXCLUDE
	PATTERN "*.a" EXCLUDE
	PATTERN "*.log" EXCLUDE
)
if(MSVC)
	install(CODE
		"
		file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/log/install)
		find_program(7Z 7z.exe HINTS \"C:/Program Files/7-Zip\")
		execute_process(COMMAND \${7Z} a
			\"${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}-${CMAKE_BUILD_TYPE}-${TOP_SYSTEM_BITNESS}.pdb.zip\"
			\"${CMAKE_PROJECT_NAME}/*.pdb\"
			WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
			OUTPUT_FILE log/install/pdb.out.log
			ERROR_FILE log/install/pdb.err.log
			RESULT_VARIABLE RETURN_CODE
		)
		if(NOT RETURN_CODE EQUAL 0)
			message(WARNING \"7z.exe Return Code: \${RETURN_CODE}\")
		endif()
		"
	)
endif()

add_subdirectory(src)
if(BUILD_TESTING)
	enable_testing()
	add_subdirectory(test)
endif()
if(BUILD_EXAMPLES)
	add_subdirectory(example)
endif()
