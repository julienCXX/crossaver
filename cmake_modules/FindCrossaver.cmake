# This script locates the Crossaver library
# Inspirated from the SFML one.
# Please set the CROSSAVER_ROOT variable to the path containing the library's
# contents if it is not in the system's standard path
# Usage example:
#   find_package(CROSSAVER REQUIRED)
#   if(CROSSAVER_FOUND)
#       include_directories(${CROSSAVER_INCLUDE_DIR})
#       target_link_libraries(myscreensaver ${CROSSAVER_LIBRARY})
#   endif()

# define the list of search paths for headers and library
set(FIND_CROSSAVER_PATHS
    ${CROSSAVER_ROOT}
    $ENV{CROSSAVER_ROOT}
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
    /sw
    /opt/local
    /opt/csw
    /opt)

# find the CROSSAVER include directory
find_path(CROSSAVER_INCLUDE_DIR crossaver.h
    PATH_SUFFIXES include
    PATHS ${FIND_CROSSAVER_PATHS})

find_library(CROSSAVER_LIBRARY
    NAMES crossaver
    PATH_SUFFIXES lib64 lib
    PATHS ${FIND_CROSSAVER_PATHS})

if(CROSSAVER_INCLUDE_DIR AND CROSSAVER_LIBRARY)
    set(CROSSAVER_FOUND TRUE)
    message(STATUS "Found Crossaver in ${CROSSAVER_INCLUDE_DIR}")
else()
    set(CROSSAVER_FOUND FALSE)
    message(FATAL_ERROR "Could not find Crossaver")
endif()
