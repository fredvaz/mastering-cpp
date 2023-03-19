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

# Set variables names
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

# Add the AddGitSubmodule
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
# Call the function
add_git_submodule(external/json)

add_subdirectory(configured)
add_subdirectory(external) # Link to a CMakeLists.txt in the external directory
add_subdirectory(src)
add_subdirectory(app)
