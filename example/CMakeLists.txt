project(example)

set(EXAMPLE_NAME ${PROJECT_NAME})

add_subdirectory(app)

install(TARGETS
	${EXAMPLE_NAME}_app

	RUNTIME DESTINATION "${PROJECT_NAME}/bin"
)
