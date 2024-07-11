project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)
add_subdirectory(connectionpool)

install(TARGETS
	${TEST_NAME}_app
	${TEST_NAME}_conv
	${TEST_NAME}_log
	${TEST_NAME}_connectionpool

	RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
	ARCHIVE DESTINATION lib
)
