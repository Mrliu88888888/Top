project(${TEST_NAME}_conv)

add_executable(${PROJECT_NAME} "test.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::gtest_main
	Conv
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
