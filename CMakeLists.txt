cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include(LinkMode)

# Project definitions
project(Crossaver)

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

# Public headers dir
include_directories(include)

# Library files
file(
    GLOB_RECURSE
    SOURCE_FILES
    src/*
    include/*
)

add_library(
    crossaver
    ${CROSSAVER_LINK_MODE}
    ${SOURCE_FILES}
)

# Detect and add SFML
if(${SFML_LINK_TYPE} EQUAL "STATIC")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(crossaver ${SFML_LIBRARIES})
    target_link_libraries(crossaver ${SFML_DEPENDENCIES})
endif()
