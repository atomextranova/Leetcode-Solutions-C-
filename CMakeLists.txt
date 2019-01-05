cmake_minimum_required (VERSION 2.6)
project (Leetcode)

option(BUILD_SUBDIR1 "Enable building subdir1" ON)

if(BUILD_SUBDIR1)
    add_subdirectory(Array)
    endif()