cmake_minimum_required(VERSION 2.6)

# Project definitions
project(SimpleText)

set(EXECUTABLE_NAME simpleText)

set(EXECUTABLE_OUTPUT_PATH bin)

# Project files
file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    ${EXECUTABLE_NAME}
    ${source_files}
)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.." ${CMAKE_MODULE_PATH})
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Add Crossaver library
include_directories(${CMAKE_SOURCE_DIR}/../../include)

file(
    GLOB
    CROSSAVER_LIBRARIES
    ../../lib/*
)

target_link_libraries(${EXECUTABLE_NAME} ${CROSSAVER_LIBRARIES})
