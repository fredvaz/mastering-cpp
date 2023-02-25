# How to Compile the Project using CMake 
# 0. Create Source (main.cc) and CMakeFile (CMakeLists.txt)
# 1. mkdir build 
# 2. cd build
# 3. cmake .. # Generating the Build Files / Configure the Project / 
# the ".." to indicate one level above in root directory where the projects files are
# 4. cmake --build .
# 5. ./ Executable

cmake_minimum_required(VERSION 3.16) 

project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

# Sets the C++ version standard for the Compiler
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# allows to enable or disable our Tests
option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

# Set variables names
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

# Add the AddGitSubmodule
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
# Note:  
# Git submodule if it is a GitHub or GitLab repository but not a CMake project!
# Use Fetch Content to CMake projects much easier to work with external dependencie/libraries
# Alternative to 
# add_git_submodule(external/json)
# in Modern CMake is 
include(FetchContent)
include(Docs)

# To declare which Git repository is to use. NOTE: Find the name in CMakeLists.txt of the library
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(nlohmann_json)

# Another example
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 9.1.0
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(fmt)

# Another example
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.11.0
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(spdlog)

# Another example
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.0.0
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(cxxopts)

# Another example
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v2.13.9
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(configured)
add_subdirectory(external) # Link to a CMakeLists.txt in the external directory
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
