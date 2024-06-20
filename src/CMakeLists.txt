project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)

install(TARGETS
	main
	qmain

	RUNTIME
	LIBRARY
	ARCHIVE
)
install(TARGETS
	App
	Conv
	Log

	EXPORT TopConfig
	RUNTIME
	LIBRARY
	ARCHIVE
)
install(DIRECTORY
	${TOP_INCLUDE}

	DESTINATION .
)
install(EXPORT TopConfig
    FILE TopConfig.cmake
    NAMESPACE Top::
    DESTINATION share/Top
)

FindTargetDependencies(main TARGET_DEPENDENCIES)
FindTargetDependencies(qmain TARGET_DEPENDENCIES)
FindTargetDependencies(App TARGET_DEPENDENCIES)
FindTargetDependencies(Conv TARGET_DEPENDENCIES)
FindTargetDependencies(Log TARGET_DEPENDENCIES)
list(REMOVE_DUPLICATES TARGET_DEPENDENCIES)
FindTargetLibraries(TARGET_DEPENDENCIES TARGET_LIBRARIES)
install(FILES 
	${TARGET_LIBRARIES}

	DESTINATION bin
)
