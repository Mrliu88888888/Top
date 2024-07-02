project(src)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(log)

install(DIRECTORY
	${EXECUTABLE_OUTPUT_PATH}/

	DESTINATION bin
	FILES_MATCHING
	PATTERN "*.exe"
	PATTERN "*.dll"
	PATTERN "*.rcc"
	PATTERN "*.qm"
)
