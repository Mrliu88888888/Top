if(WIN32)
	find_program(WINDEPLOYQT windeployqt.exe)
	find_path(QT_BIN_PATH qmake.exe)
	function(DEPLOYQT TARGET_NAME)
		install(CODE
			"
			execute_process(COMMAND ${WINDEPLOYQT}
				--qmldir ${QT_BIN_PATH}/../qml ${TARGET_NAME}.exe
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
			execute_process(COMMAND ${LINUXDEPLOY}
				${TARGET_NAME} .
				WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
				RESULT_VARIABLE RETURN_CODE
			)
			if(NOT RETURN_CODE EQUAL 0)
				message(FATAL_ERROR \"LinuxDeploy.sh Return Code: \${RETURN_CODE}\")
			endif()
			"
		)
	endfunction()

	set(CMAKE_SKIP_RPATH TRUE)
	find_program(LINUXDEPLOYQT linuxdeployqt)
	find_path(QT_BIN_PATH qmake)
	function(DEPLOYQT TARGET_NAME)
		install(CODE
			"
			execute_process(COMMAND ${LINUXDEPLOYQT}
				${TARGET_NAME} -qmake=${QT_BIN_PATH}/qmake -qmldir=${QT_BIN_PATH}/../qml
				WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
				RESULT_VARIABLE RETURN_CODE
			)
			if(NOT RETURN_CODE EQUAL 0)
				message(FATAL_ERROR \"linuxdeployqt Return Code: \${RETURN_CODE}\")
			endif()
			"
		)
	endfunction()

	function(LINK_FILE FILE_NAME LINK_FILE_NAME)
		install(CODE
			"
			execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
				${FILE_NAME} ${LINK_FILE_NAME}
				WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
			)
			"
		)
	endfunction()

	function(INSTALL_TARGET_START_SCRIPT TARGET_NAME)
		install(FILES "${CMAKE_SOURCE_DIR}/script/linux/LinuxRelease.sh"
			DESTINATION bin
			PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
			RENAME ${TARGET_NAME}.sh
		)
	endfunction()

	function(INSTALL_TARGET_PROTECT_SCRIPT TARGET_NAME)
		install(FILES "${CMAKE_SOURCE_DIR}/script/linux/iprotectyou.sh"
			DESTINATION bin
			PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
			RENAME ${TARGET_NAME}.sh
		)
	endfunction()
endif()
