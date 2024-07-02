project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)
if(BUILD_PROJ_SQLITERPC)
	add_subdirectory(SQLiteRPC)
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	add_subdirectory(VideoCamera)
endif()

install(TARGETS
	main
	qmain

	RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
	ARCHIVE DESTINATION lib
)
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
