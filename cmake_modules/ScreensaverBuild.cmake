# Screensaver production adjustments
# To be called from a screensaver's CMake file
# You have to define the SRC_FILES variable
# e.g. file(GLOB_RECURSE SRC_FILES src/*)

include(LinkMode)

string(TOLOWER ${PROJECT_NAME} EXECUTABLE_NAME)

if(NOT SRC_FILES)
    MESSAGE(FATAL_ERROR "SRC_FILES is not defined")
endif()

# Set binary generation path if nonexistant
if(NOT EXECUTABLE_OUTPUT_PATH)
    set(EXECUTABLE_OUTPUT_PATH bin)
endif()

add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

if(${SFML_LINK_TYPE} STREQUAL "STATIC")
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

# OS-specific adjustments
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES SUFFIX ".scr")
endif()
