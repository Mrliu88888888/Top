project(main)

add_executable(${PROJECT_NAME}
	"main.cpp"
	"pcm.cpp"
	"mnew.cpp"
)
target_include_directories(${PROJECT_NAME} PRIVATE
	${SIMPLEINI_INCLUDE_DIRS}
	"${CMAKE_BINARY_DIR}/include"
	"${TOP_THIRDPARTY}/ThreadPool/include"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	unofficial::concurrentqueue::concurrentqueue
	mimalloc
	App
)
