project(Conv)

add_library(${PROJECT_NAME} SHARED "Conv.cpp")
target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_CONV_EXPORTS)
target_include_directories(${PROJECT_NAME} PUBLIC
	${TOP_INCLUDE}
)
