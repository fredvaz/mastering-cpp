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

# Option for the below IF condition / Only compiles our Library file
# During the project build we can set the variable using:
# 1. cmake .. -DCOMPILE_EXECUTABLE=ON
# 2. cmkae --build .
option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)

add_subdirectory(src)
if(COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("Whitout exe. compiling")
endif()