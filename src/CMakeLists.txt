project(src)

add_subdirectory(TODO)

install(DIRECTORY
	${EXECUTABLE_OUTPUT_PATH}/

	DESTINATION bin
	FILES_MATCHING
	PATTERN "*.exe"
	PATTERN "*.out"
	PATTERN "*.dll"
	PATTERN "*.so"
	PATTERN "*.so.*"
	PATTERN "*.rcc"
	PATTERN "*.qm"
)
