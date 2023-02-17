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

# hangover in the key function to see information about it 
add_executable(Executable main.cc)