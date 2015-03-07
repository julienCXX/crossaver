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

