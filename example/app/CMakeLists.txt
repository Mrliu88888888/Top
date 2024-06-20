project(${EXAMPLE_NAME}_app)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE
	${TOP}App ${TOP}Conv ${TOP}Log
)
