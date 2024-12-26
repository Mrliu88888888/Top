project(qmlmain)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE ${QT}::Quick)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
