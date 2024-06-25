project(SQLiteRPC)

add_subdirectory(Lite)
add_subdirectory(LiteService)
add_subdirectory(LiteStudio)
add_subdirectory(LiteRPC/gRPC)

install(TARGETS
	Lite
	LiteService
	LiteStudio
	LiteRPC

	RUNTIME
	LIBRARY
	ARCHIVE
)

FIND_TARGET_DEPENDENCIES(TARGET_DEPENDENCIES 
	Lite
	LiteService
	LiteStudio
	LiteRPC
)
FIND_TARGET_LIBRARIES(TARGET_DEPENDENCIES TARGET_LIBRARIES)
install(FILES 
	${TARGET_LIBRARIES}

	DESTINATION bin
)
