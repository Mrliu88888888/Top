project(src)

add_subdirectory(Top)
add_subdirectory(main)
add_subdirectory(qmain)
add_subdirectory(qmlchatui)
add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)
add_subdirectory(connectionpool)

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
DEPLOYQT(qmain bin)
DEPLOYQT(qmlchatui bin)
if(WIN32)
	install(DIRECTORY
		${QT_BIN_PATH}/../qml/Qt/labs/platform  # qmlchatui/qml/WeChat.qml using import Qt.labs.platform 1.1

		DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Qt/labs
	)
endif()
