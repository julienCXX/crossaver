cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake_modules" ${CMAKE_MODULE_PATH})

# Project definitions
project(Colors)

# Project files
file(
    GLOB_RECURSE
    SRC_FILES
    src/*
)

# Screensaver production adjustments
include(ScreensaverBuild)

# Add Crossaver library (required to be done before adding SFML)
set(CROSSAVER_ROOT ${CMAKE_SOURCE_DIR}/../..)

find_package(Crossaver REQUIRED)
if(CROSSAVER_FOUND)
    include_directories(${CROSSAVER_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${CROSSAVER_LIBRARY})
endif()

# Detect and add SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    # required when static linking
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
endif()
