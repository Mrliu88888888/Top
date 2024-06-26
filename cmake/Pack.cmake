set(CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION}-${CMAKE_BUILD_TYPE})
set(CPACK_PACKAGE_DESCRIPTION "GOOD LUCK")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${CPACK_PACKAGE_DESCRIPTION})
set(CPACK_PACKAGE_VENDOR "liumeng")
set(CPACK_PACKAGE_CONTACT "liumeng1105@outlook.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_CONTACT})
if(WIN32)
	set(CPACK_GENERATOR "ZIP;NSIS64")
elseif(UNIX)
	set(CPACK_GENERATOR "TGZ;DEB")
endif()

include(CPack)
