project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)

install(TARGETS
	main
	qmain
	App
	Conv
	Log

	RUNTIME
	LIBRARY
	ARCHIVE
)
install(DIRECTORY
	${TOP_INCLUDE}

	DESTINATION .
)
