cmake_minimum_required(VERSION 2.6)

# Project definitions
project(Colors)

set(EXECUTABLE_NAME colors)

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

# Add Crossaver library (required to be done before adding SFML)
include_directories(${CMAKE_SOURCE_DIR}/../../include)

file(
    GLOB
    CROSSAVER_LIBRARIES
    ../../lib/*
)

target_link_libraries(${EXECUTABLE_NAME} ${CROSSAVER_LIBRARIES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake_modules" ${CMAKE_MODULE_PATH})
#See the FindSFML.cmake file for additional details and instructions
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES}) # required when static linking
endif()
