project(example)

set(EXAMPLE_NAME ${PROJECT_NAME})

find_package(Top CONFIG REQUIRED)

add_subdirectory(app)

install(TARGETS
	${EXAMPLE_NAME}_app

	RUNTIME
)
