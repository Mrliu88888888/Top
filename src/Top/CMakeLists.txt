project(Top)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QML_QRC_FILE "${CMAKE_CURRENT_SOURCE_DIR}/qml.qrc")
set(QML_RCC_FILE "${EXECUTABLE_OUTPUT_PATH}/rcc/qml.rcc")
file(GLOB_RECURSE QML_FILES "${CMAKE_CURRENT_SOURCE_DIR}/qml/*.qml")
add_custom_command(
	OUTPUT ${QML_RCC_FILE}
	COMMAND rcc --binary ${QML_QRC_FILE} -o ${QML_RCC_FILE}
	DEPENDS ${QML_QRC_FILE} ${QML_FILES}
)
add_custom_target(QML_RCC ALL DEPENDS ${QML_RCC_FILE})

add_executable(${PROJECT_NAME} "main.cpp" "res.qrc")
if(WIN32)
	target_sources(${PROJECT_NAME} PRIVATE "res/Top.rc")
endif()
if(WIN32 AND NOT TOP_DEBUG)
	set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
	# set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
endif()
target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_BINARY_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT}::Quick)
add_dependencies(${PROJECT_NAME} QML_RCC)

DEPLOYQT(${PROJECT_NAME} bin)
install(FILES ${QML_RCC_FILE} DESTINATION bin/rcc)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
