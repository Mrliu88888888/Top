project(qmlchatui)

if(MSVC AND NOT TOP_DEBUG)
	set(QT_WIN32 WIN32)
endif()
add_executable(${PROJECT_NAME} ${QT_WIN32} "main.cpp" "res.qrc" "qml.qrc")
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT}::Quick)

if(WIN32)
	find_program(WINDEPLOYQT windeployqt.exe)
	find_path(QT_BIN_PATH qmake.exe)
	install(CODE
		"
		execute_process(COMMAND ${WINDEPLOYQT} --qmldir ${QT_BIN_PATH}/../qml ${PROJECT_NAME}.exe
			WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
			RESULT_VARIABLE RETURN_CODE
		)
		if(NOT RETURN_CODE EQUAL 0)
			message(FATAL_ERROR \"windeployqt.exe Return Code: \${RETURN_CODE}\")
		endif()
		"
	)
elseif(UNIX)
	find_program(LINUXDEPLOY LinuxDeploy.sh HINTS "${CMAKE_SOURCE_DIR}/script/linux")
	install(CODE
		"
		execute_process(COMMAND ${LINUXDEPLOY} ${PROJECT_NAME} .
			WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
			RESULT_VARIABLE RETURN_CODE
		)
		if(NOT RETURN_CODE EQUAL 0)
			message(FATAL_ERROR \"LinuxDeploy.sh Return Code: \${RETURN_CODE}\")
		endif()
		"
	)
endif()
