get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${TEST_NAME}_${CURRENT_DIR_NAME})

add_executable(${PROJECT_NAME} "test.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main ConnectionPool)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
