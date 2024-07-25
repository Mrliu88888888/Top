project(qmlchatui)

if(MSVC AND NOT TOP_DEBUG)
	set(QT_WIN32 WIN32)
endif()
add_executable(${PROJECT_NAME} ${QT_WIN32} "main.cpp" "res.qrc" "qml.qrc")
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT}::Quick)
