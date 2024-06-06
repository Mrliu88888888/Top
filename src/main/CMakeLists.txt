project(main)

add_executable(${PROJECT_NAME} "main.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_BINARY_DIR}/include"
)
