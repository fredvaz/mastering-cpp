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

# Added the src directory: BAD practice
# add_library(Library STATIC src/my_lib.cc) # Moved to CMakeLists.txt in src/ directory

# Added the app directory: BAD practice
#add_executable(Executable app/main.cc) # Moved to CMakeLists.txt in app/ directory

#target_link_libraries(Executable PUBLIC Library) # Moved to CMakeLists.txt in app/ directory

# Yet, fatal error: my_lib.h: No such file or directory
# [build]     2 | #include "my_lib.h"

# Added to search for other CMakeLists.txt
add_subdirectory(src)
add_subdirectory(app)