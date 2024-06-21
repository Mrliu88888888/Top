project(Log)

add_library(${PROJECT_NAME} "Log.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_EXPORTS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC TOP_SHARED)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${TOP_INCLUDE}/log>
	$<INSTALL_INTERFACE:include/log>

	$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
target_link_libraries(${PROJECT_NAME} PUBLIC fmt::fmt)
