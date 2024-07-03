project(src)

add_subdirectory(TODO)

install(TARGETS


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
