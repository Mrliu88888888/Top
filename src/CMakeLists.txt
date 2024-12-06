project(src)

add_subdirectory(Top)
add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(qmlchatui)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)
add_subdirectory(connectionpool)

install(TARGETS
	App
	Conv
	Log

	EXPORT TopConfig
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
	ARCHIVE DESTINATION lib
)
install(EXPORT TopConfig
	FILE TopConfig.cmake
	NAMESPACE Top::
	DESTINATION share/Top
)
