project(main)

add_executable(${PROJECT_NAME}
	"main.cpp"
	"pcm.cpp"
	"mnew.cpp"
	"connpool.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	${SIMPLEINI_INCLUDE_DIRS}
	${TOP_THREADPOOL_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	unofficial::concurrentqueue::concurrentqueue Threads::Threads
	App ConnectionPool
)
if(USING_MIMALLOC)
	target_compile_definitions(${PROJECT_NAME} PRIVATE USING_MIMALLOC)
	target_link_libraries(${PROJECT_NAME} PRIVATE mimalloc)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
