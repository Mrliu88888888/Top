project(qmain)

set(APP_QRC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/app.qrc")
set(APP_RCC_FILE "${EXECUTABLE_OUTPUT_PATH}/rcc/app.rcc")
add_custom_command(
	OUTPUT ${APP_RCC_FILE}
	COMMAND rcc --binary ${APP_QRC_FILE} -o ${APP_RCC_FILE}
	DEPENDS ${APP_QRC_FILE}
)
add_custom_target(APP_RCC ALL DEPENDS ${APP_RCC_FILE})

add_executable(${PROJECT_NAME} "main.cpp")
add_dependencies(${PROJECT_NAME} APP_RCC)
target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt5::Core Qt5::Gui Qt5::Widgets
	App
)

if(WIN32)
	find_program(WINDEPLOYQT windeployqt.exe)
	install(CODE
		"
		execute_process(COMMAND ${WINDEPLOYQT} ${PROJECT_NAME}.exe
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
