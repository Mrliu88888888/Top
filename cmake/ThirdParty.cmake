find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(unofficial-concurrentqueue CONFIG REQUIRED)
if(USING_MIMALLOC)
	find_package(mimalloc CONFIG REQUIRED)
endif()
set(TOP_THREADPOOL_INCLUDE_DIRS "${TOP_THIRDPARTY}/ThreadPool/include")
if(NOT EXISTS ${TOP_THREADPOOL_INCLUDE_DIRS})
	message(FATAL_ERROR "${TOP_THREADPOOL_INCLUDE_DIRS} not exists")
endif()

execute_process(
	COMMAND qmake -query QT_VERSION
	OUTPUT_VARIABLE QT_VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(QT_VERSION VERSION_GREATER_EQUAL "6.0.0")
	set(QT Qt6)
elseif(QT_VERSION VERSION_GREATER_EQUAL "5.0.0")
	set(QT Qt5)
else()
	message(FATAL_ERROR "Unsupported Qt version: ${QT_VERSION}")
endif()
if(QT)
	message(STATUS "Using Qt version: ${QT_VERSION}")
	find_package(${QT} COMPONENTS Core Gui Widgets Quick REQUIRED)
endif()
