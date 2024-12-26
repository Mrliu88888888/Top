project(src)

add_subdirectory(Top)
add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(qmlmain)
add_subdirectory(log)
add_subdirectory(connectionpool)
add_subdirectory(qmlchatui)

install(TARGETS
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
