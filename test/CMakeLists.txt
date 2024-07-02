project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(app)

install(TARGETS
	${TEST_NAME}_app

	RUNTIME DESTINATION bin
)
