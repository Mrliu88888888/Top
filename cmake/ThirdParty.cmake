find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
if(BUILD_TESTING)
	find_package(GTest CONFIG REQUIRED)
endif()

if(USE_QT_GUI)
	execute_process(COMMAND qmake
		-query QT_VERSION
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
		find_package(${QT} COMPONENTS Quick REQUIRED)
	endif()
endif()

add_subdirectory(${TOP_THIRDPARTY}/ThreadPool) # export
													   # THIRDPARTY_THREADPOOL_INCLUDE_DIRS
