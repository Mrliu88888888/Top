project(src)

add_subdirectory(main)
add_subdirectory(app)
add_subdirectory(log)

install(TARGETS
	App
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
install(DIRECTORY
	${TOP_EXPORT_INCLUDE}

	DESTINATION .
)
install(DIRECTORY
	${EXECUTABLE_OUTPUT_PATH}/

	DESTINATION bin
	FILES_MATCHING
	PATTERN "*.exe"
	PATTERN "*.dll"
	PATTERN "*.rcc"
	PATTERN "*.qm"
)
