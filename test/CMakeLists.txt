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

list(APPEND TARGET_DEPENDENCIES GTest::gtest_main)
list(APPEND TARGET_DEPENDENCIES GTest::gtest)
FIND_TARGET_LIBRARIES(TARGET_DEPENDENCIES TARGET_LIBRARIES)
install(FILES
	${TARGET_LIBRARIES}

	DESTINATION bin
)
