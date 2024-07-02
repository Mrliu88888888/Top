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

	RUNTIME DESTINATION ${PROJECT_NAME}
)
