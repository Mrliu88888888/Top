project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(qmlmain)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)
add_subdirectory(connectionpool)
if(BUILD_PROJ_SQLITERPC)
	add_subdirectory(SQLiteRPC)
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	add_subdirectory(VideoCamera)
endif()

install(TARGETS
	main
	qmain
	qmlmain
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
