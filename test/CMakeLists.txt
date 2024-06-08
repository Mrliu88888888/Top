project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(app)
add_subdirectory(conv)
