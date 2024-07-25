project(src)

add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(qmlchatui)
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
	qmlchatui
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
	PATTERN "*"
	PATTERN "*.exp" EXCLUDE
	PATTERN "*.ilk" EXCLUDE
	PATTERN "*.lib" EXCLUDE
	PATTERN "*.pdb" EXCLUDE
)
if(WIN32)
	install(CODE
		"
		execute_process(COMMAND ${WINDEPLOYQT} --qmldir ${QT_BIN_PATH}/../qml qmlchatui.exe
			WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
			RESULT_VARIABLE RETURN_CODE
		)
		if(NOT RETURN_CODE EQUAL 0)
			message(FATAL_ERROR \"windeployqt.exe Return Code: \${RETURN_CODE}\")
		endif()
		"
	)
	install(DIRECTORY
		${QT_BIN_PATH}/../qml/Qt/labs/platform

		DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Qt/labs
	)
elseif(UNIX)
	install(CODE
		"
		execute_process(COMMAND ${LINUXDEPLOY} qmlchatui .
			WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
			RESULT_VARIABLE RETURN_CODE
		)
		if(NOT RETURN_CODE EQUAL 0)
			message(FATAL_ERROR \"LinuxDeploy.sh Return Code: \${RETURN_CODE}\")
		endif()
		"
	)
endif()
