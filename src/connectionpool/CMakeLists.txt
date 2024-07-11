project(ConnectionPool)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
	$<BUILD_INTERFACE:${TOP_EXPORT_INCLUDE}/connectionpool>
	$<INSTALL_INTERFACE:include/connectionpool>
)
target_link_libraries(${PROJECT_NAME} INTERFACE
	unofficial::concurrentqueue::concurrentqueue
)
