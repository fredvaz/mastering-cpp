cmake_minimum_required(VERSION 3.13)

project(googletest_sample)

set(CMAKE_CXX_STANDARD 11)

# get google test library with FetchContent introduced in CMake version 3.13
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()


add_library(database_connection_library IDatabaseConnection.cpp)
add_library(employee_manager_library EmployeeManager.cpp)

set(MY_LIBRARIES database_connection_library employee_manager_library)


add_executable(main_app main.cpp)
target_link_libraries(main_app ${MY_LIBRARIES})

add_executable(test_runner test.cpp)
target_link_libraries(test_runner ${MY_LIBRARIES} gtest_main gmock_main pthread)