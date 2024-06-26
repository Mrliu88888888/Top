find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(unofficial-concurrentqueue CONFIG REQUIRED)
# find_package(nlohmann_json CONFIG REQUIRED)
find_package(Iconv REQUIRED)
find_path(SIMPLEINI_INCLUDE_DIRS "ConvertUTF.c")
if(NOT SIMPLEINI_INCLUDE_DIRS)
	message(FATAL_ERROR "simpleini not found")
endif()
if(USING_MIMALLOC)
	find_package(mimalloc CONFIG REQUIRED)
endif()
if(BUILD_PROJ_SQLITERPC)
	find_package(gRPC CONFIG REQUIRED)
	find_package(protobuf CONFIG REQUIRED)
endif()
if(BUILD_PROJ_VIDEOCAMERA)
	find_package(OpenCV REQUIRED)
endif()
