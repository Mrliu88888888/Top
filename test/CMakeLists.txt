project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(log)
add_subdirectory(connectionpool)
