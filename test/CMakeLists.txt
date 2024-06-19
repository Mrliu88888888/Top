project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)

install(TARGETS
	${TEST_NAME}_app
	${TEST_NAME}_conv
	${TEST_NAME}_log

	RUNTIME
)
