project(App)

add_library(${PROJECT_NAME} SHARED "App.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_BINARY_DIR}/include"
)
target_compile_definitions(${PROJECT_NAME} PRIVATE TOP_APP_EXPORTS)
target_include_directories(${PROJECT_NAME} PUBLIC
	${TOP_INCLUDE}
)
