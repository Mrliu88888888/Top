project(Log)

add_library(${PROJECT_NAME} "Log.cpp")
if(BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_EXPORTS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC TOP_SHARED)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${TOP_EXPORT_INCLUDE}/log>
	$<INSTALL_INTERFACE:include/log>

	$<BUILD_INTERFACE:${TOP_BINARY_INCLUDE}>
	$<INSTALL_INTERFACE:include>
)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog)
