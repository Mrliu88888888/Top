project(test)

find_package(GTest CONFIG REQUIRED)

set(TEST_NAME ${PROJECT_NAME})

add_subdirectory(app)
add_subdirectory(conv)
add_subdirectory(log)

install(TARGETS
	${TEST_NAME}_app
	${TEST_NAME}_conv
	${TEST_NAME}_log

	RUNTIME
)

FindTargetDependencies(${TEST_NAME}_app LIBS)
FindTargetDependencies(${TEST_NAME}_conv LIBS)
FindTargetDependencies(${TEST_NAME}_log LIBS)
list(REMOVE_DUPLICATES TARGET_DEPENDENCIES)
FindTargetLibraries(TARGET_DEPENDENCIES TARGET_LIBRARIES)
install(FILES 
	${TARGET_LIBRARIES}

	DESTINATION bin
)
