project(main)

add_executable(${PROJECT_NAME}
	"main.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_BINARY_DIR}/include"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	App Log
)
if(USING_MIMALLOC)
	target_compile_definitions(${PROJECT_NAME} PRIVATE USING_MIMALLOC)
	target_link_libraries(${PROJECT_NAME} PRIVATE mimalloc)
endif()
