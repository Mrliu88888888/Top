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

FIND_TARGET_DEPENDENCIES(TARGET_DEPENDENCIES
	main
	qmain
	App
	Conv
	Log
)
FIND_TARGET_LIBRARIES(TARGET_DEPENDENCIES TARGET_LIBRARIES)
if(WIN32)
	set(DEPEND_DLL
		"${EXECUTABLE_OUTPUT_PATH}/mimalloc-redirect.dll"
		"${EXECUTABLE_OUTPUT_PATH}/iconv-2.dll"
	)
endif()
install(FILES
	${TARGET_LIBRARIES}
	${DEPEND_DLL}

	DESTINATION bin
)
