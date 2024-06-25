project(LiteStudio)

add_executable(${PROJECT_NAME}
	"main.cpp"
	"LiteStudio/LiteStudio.cpp"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt5::Core Qt5::Gui Qt5::Widgets
	LiteRPC
)
