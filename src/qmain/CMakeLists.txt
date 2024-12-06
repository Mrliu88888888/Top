project(qmain)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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
	${QT}::Core ${QT}::Gui ${QT}::Widgets
	App
)

DEPLOYQT(qmain bin)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
