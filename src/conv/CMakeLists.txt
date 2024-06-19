project(Conv)

add_library(${PROJECT_NAME} "Conv.cpp")
if (${BUILD_SHARED_LIBS})
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_CONV_EXPORTS)
else ()
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_CONV_STATIC)
endif ()
target_link_libraries(${PROJECT_NAME} PRIVATE
	Iconv::Iconv
)
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${TOP_INCLUDE}/conv>
	$<INSTALL_INTERFACE:include/conv>
)
