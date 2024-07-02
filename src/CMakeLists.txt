project(src)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(log)

install(TARGETS
	main
	App
	Log

	RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
)
