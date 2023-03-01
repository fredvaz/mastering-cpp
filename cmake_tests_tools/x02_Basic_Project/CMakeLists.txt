# How to Compile the Project using CMake 
# 0. Create Source (main.cc) and CMakeFile (CMakeLists.txt)
# 1. mkdir build 
# 2. cd build
# 3. cmake .. # Generating the Build Files / Configure the Project / 
# the ".." to indicate one level above in root directory where the projects files are
# 4. cmake --build .
# 5. ./ Executable

# check the installed version using cmake --version
cmake_minimum_required(VERSION 3.16) 

# project version and support languages C and C++
project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

# add the "my_lib.h" library
add_library(Library STATIC my_lib.cc)

# hangover in the key function to see information about it 
add_executable(Executable main.cc)

# adds the link of the library with the executable
target_link_libraries(Executable PUBLIC Library)

# Notes: We created here a library which is a new target. So, if we just want to check if our
# library compiles, we do not have to compile our executable, following the commands:
# 1. cmake -- build . --target Library
#
# Otherwise if we want to compile our Executaable we need the Library because we set it
# as a PUBLIC dependency in target_link_libraries
# 1. cmake -- build . --target Executable
