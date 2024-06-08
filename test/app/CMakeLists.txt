project(test_app)

add_executable(${PROJECT_NAME}
	"test_app.cpp"
)
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
