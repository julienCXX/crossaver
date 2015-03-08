cmake_minimum_required(VERSION 2.6)

# Project definitions
project(Crossaver)

set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})

# Public headers dir
include_directories(include)

# Library files
file(
    GLOB_RECURSE
    source_files
    src/*
    include/*
)

add_library(
    crossaver
    STATIC
    ${source_files}
)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#See the FindSFML.cmake file for additional details and instructions
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(crossaver ${SFML_LIBRARIES})
    target_link_libraries(crossaver ${SFML_DEPENDENCIES})
endif()
