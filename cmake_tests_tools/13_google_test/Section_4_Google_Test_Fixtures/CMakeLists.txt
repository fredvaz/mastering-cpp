cmake_minimum_required(VERSION 3.13)

project(googletest_sample)

# get google test library with FetchContent introduced in CMake version 3.13
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)

FetchContent_GetProperties(googletest)
# The above function will set the following variables:
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()


add_library(library_code STATIC LibraryCode.cpp)


add_executable(main_app main.cpp)
target_link_libraries(main_app library_code)


add_executable(test_runner test.cpp)
target_link_libraries(test_runner library_code gtest_main gmock_main)