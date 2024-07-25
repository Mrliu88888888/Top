if(WIN32)
	find_program(WINDEPLOYQT windeployqt.exe)
	find_path(QT_BIN_PATH qmake.exe)
	function(DEPLOYQT TARGET_NAME)
		install(CODE
			"
			execute_process(COMMAND ${WINDEPLOYQT} --qmldir ${QT_BIN_PATH}/../qml ${TARGET_NAME}.exe
				WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
				RESULT_VARIABLE RETURN_CODE
			)
			if(NOT RETURN_CODE EQUAL 0)
				message(FATAL_ERROR \"windeployqt.exe Return Code: \${RETURN_CODE}\")
			endif()
			"
		)
	endfunction()
elseif(UNIX)
	find_program(LINUXDEPLOY LinuxDeploy.sh HINTS "${CMAKE_SOURCE_DIR}/script/linux")
	function(DEPLOYLINUX TARGET_NAME)
		install(CODE
			"
			execute_process(COMMAND ${LINUXDEPLOY} ${TARGET_NAME} .
				WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
				RESULT_VARIABLE RETURN_CODE
			)
			if(NOT RETURN_CODE EQUAL 0)
				message(FATAL_ERROR \"LinuxDeploy.sh Return Code: \${RETURN_CODE}\")
			endif()
			"
		)
	endfunction()
	function(DEPLOYQT TARGET_NAME)
		DEPLOYLINUX(${TARGET_NAME})
	endfunction()
endif()
