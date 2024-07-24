project(LiteStudio)

add_executable(${PROJECT_NAME}
	"main.cpp"
	"LiteStudio/LiteStudio.cpp"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	${QT}::Core ${QT}::Gui ${QT}::Widgets
	LiteRPC
)
