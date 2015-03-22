# Default settings for library linking

if(NOT CROSSAVER_LINK_TYPE)
    set(CROSSAVER_LINK_TYPE "DEFAULT")
endif()

if(NOT SFML_LINK_TYPE)
    set(SFML_LINK_TYPE "DEFAULT")
endif()

if(${SFML_LINK_TYPE} STREQUAL "DEFAULT")
    # CMAKE_SYSTEM_NAME is empty at this step and thus cannot be used
    if(WIN32)
        set(SFML_LINK_TYPE "STATIC")
    else()
        set(SFML_LINK_TYPE "DYNAMIC")
    endif()
endif()

if(${CROSSAVER_LINK_TYPE} STREQUAL "DEFAULT")
    set(CROSSAVER_LINK_TYPE "STATIC")
endif()
