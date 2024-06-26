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
install(DIRECTORY
	${TOP_INCLUDE}

	DESTINATION .
)
install(EXPORT TopConfig
	FILE TopConfig.cmake
	NAMESPACE Top::
	DESTINATION share/Top
)

set(INSTALL_TARGET_LIST
	main
	qmain
	App
	Conv
	Log
)
if(WIN32)
	FIND_TARGET_DEPENDENCIES(TARGET_DEPENDENCIES ${INSTALL_TARGET_LIST})
	FIND_TARGET_LIBRARIES(TARGET_LIBRARIES TARGET_DEPENDENCIES)
	set(DEPEND_DLL
		"${EXECUTABLE_OUTPUT_PATH}/iconv-2.dll"
		$<$<BOOL:${USING_MIMALLOC}>:${EXECUTABLE_OUTPUT_PATH}/mimalloc-redirect.dll>
	)
	install(FILES
		${TARGET_LIBRARIES}
		${DEPEND_DLL}

		DESTINATION bin
	)
elseif(UNIX)
	COPY_TARGET_DEPENDENCIES(INSTALL_TARGET_LIST)
	install(DIRECTORY
		"${CMAKE_INSTALL_PREFIX}/bin"
		DESTINATION .
	)
endif()
