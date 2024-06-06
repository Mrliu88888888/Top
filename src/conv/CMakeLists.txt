project(Conv)

add_library(${PROJECT_NAME} SHARED "Conv.cpp")
if (${BUILD_SHARED_LIBS})
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_CONV_EXPORTS)
else ()
	target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_CONV_STATIC)
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC
	${TOP_INCLUDE}
)
