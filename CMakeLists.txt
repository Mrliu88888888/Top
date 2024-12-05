cmake_minimum_required(VERSION 3.22)

option(BUILD_TESTING "build tests" ON)
option(BUILD_SHARED_LIBS "build using shared libraries" ON)
option(USE_QT_GUI "enable building with Qt GUI support" ON)

if(BUILD_TESTING)
	list(APPEND VCPKG_MANIFEST_FEATURES "test")
endif()

project(Top VERSION 1.0.0)

message(STATUS "${PROJECT_NAME} build tests: ${BUILD_TESTING}")
message(STATUS "${PROJECT_NAME} build using shared libraries: ${BUILD_SHARED_LIBS}")
message(STATUS "${PROJECT_NAME} enable Qt GUI support: ${USE_QT_GUI}")

include(cmake/Common.cmake)
include(cmake/Pack.cmake)
include(cmake/PackUtils.cmake)
include(cmake/ThirdParty.cmake)

install(FILES "CHANGELOG.md" DESTINATION .)
install(DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/
	DESTINATION bin
	FILES_MATCHING
	PATTERN "*"
	PATTERN "*.exp" EXCLUDE
	PATTERN "*.ilk" EXCLUDE
	PATTERN "*.lib" EXCLUDE
	PATTERN "*.pdb" EXCLUDE
	PATTERN "*.a" EXCLUDE
)

add_subdirectory(src)
if(BUILD_TESTING)
	add_subdirectory(test)
endif()
