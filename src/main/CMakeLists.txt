project(main)

add_executable(${PROJECT_NAME}
	"main.cpp"
)
if(USING_MIMALLOC)
	target_compile_definitions(${PROJECT_NAME} PRIVATE USING_MIMALLOC)
	target_link_libraries(${PROJECT_NAME} PRIVATE mimalloc)
endif()
