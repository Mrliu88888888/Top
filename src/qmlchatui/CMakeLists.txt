project(qmlchatui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(MSVC AND NOT TOP_DEBUG)
	set(QT_WIN32 WIN32)
endif()
add_executable(${PROJECT_NAME} ${QT_WIN32} "main.cpp"
	"res.qrc" "qml.qrc"
	"ChatListModel/ChatListModel.cpp"
	"FpsItem/FpsItem.cpp"
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT}::Quick)

DEPLOYQT(qmlchatui bin)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(DIRECTORY
	${QT_BIN_PATH}/../qml/Qt/labs/platform  # qmlchatui/qml/WeChat.qml using import Qt.labs.platform 1.1
	DESTINATION bin/qml/Qt/labs
)
