project(Conv)

add_library(${PROJECT_NAME} "Conv.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE
	Iconv::Iconv
)
if(BUILD_SHARED_LIBS)
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_EXPORTS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC TOP_SHARED)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${TOP_EXPORT_INCLUDE}/conv>
	$<INSTALL_INTERFACE:include/conv>

	$<BUILD_INTERFACE:${TOP_BINARY_INCLUDE}>
	$<INSTALL_INTERFACE:include>
)
