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

function (deploy target output)
	get_target_property(LINK_LIBS ${target} INTERFACE_LINK_LIBRARIES)
	if (NOT LINK_LIBS)
		get_target_property(LINK_LIBS ${target} LINK_LIBRARIES)
	endif ()

	foreach (LINK_LIB IN LISTS LINK_LIBS)
		if (TARGET ${LINK_LIB})
			list(APPEND ${output} ${LINK_LIB})
			deploy(${LINK_LIB} ${output})
		endif ()
	endforeach ()

	set(${output} ${${output}} PARENT_SCOPE)
endfunction ()

deploy(${TEST_NAME}_app LIBS)
deploy(${TEST_NAME}_conv LIBS)
deploy(${TEST_NAME}_log LIBS)
list(REMOVE_DUPLICATES LIBS)

foreach(lib IN LISTS LIBS)
    if (TARGET ${lib})
        if (TOP_DEBUG)
            get_target_property(dll_path ${lib} IMPORTED_LOCATION_DEBUG)
        else ()
            get_target_property(dll_path ${lib} IMPORTED_LOCATION_RELEASE)
        endif ()
        if (dll_path)
            install(FILES ${dll_path} DESTINATION bin)
        endif()
    endif()
endforeach()
