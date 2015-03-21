# Default settings for library linking

if(NOT CROSSAVER_LINK_TYPE)
    set(CROSSAVER_LINK_TYPE "DEFAULT")
endif()

if(NOT SFML_LINK_TYPE)
    set(SFML_LINK_TYPE "DEFAULT")
endif()

if(${SFML_LINK_TYPE} EQUAL "DEFAULT")
    if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(${SFML_LINK_TYPE} "STATIC")
    else()
        set(${SFML_LINK_TYPE} "DYNAMIC")
    endif()
endif()

if(${CROSSAVER_LINK_TYPE} EQUAL "DEFAULT")
    set(${CROSSAVER_LINK_TYPE} "STATIC")
endif()
