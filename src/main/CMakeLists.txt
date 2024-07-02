project(main)

add_executable(${PROJECT_NAME}
	"main.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_CONFIG_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE
	App Log
)
