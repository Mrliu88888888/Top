cmake_minimum_required(VERSION 3.22)

project(example)

set(EXAMPLE_NAME ${PROJECT_NAME})

set(TOP)
if(NOT BUILD_EXAMPLES)
	find_package(Top CONFIG REQUIRED)
	find_package(fmt CONFIG REQUIRED)  # fix me
	set(TOP Top::)
endif()

add_subdirectory(app)
