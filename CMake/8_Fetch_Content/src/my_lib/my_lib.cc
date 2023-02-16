#include <iostream>

#include "my_lib.h"

// Fetched Libraries: build/_deps directory
#include <nlohmann/json.hpp>

// Note: To get teh correct Intelli completeness we have to:
// reconfigure our project: CMake Select -> Debug and Select Kit -> g++
// Command Pallete -> CMake: Delete Cache and Reconfigure


void print_hello_world()
{
    std::cout << "Hello World!\n";

    // Just to use command: cmake -- build . --target Library to chek the Compiler error
    // generated only with the Compilation of the Library/my_lib file
    // int x = "A"; 

    std::cout << "JSON Lib Version: " << NLOHMANN_JSON_VERSION_MAJOR << "."
                                     << NLOHMANN_JSON_VERSION_MINOR << "."
                                     << NLOHMANN_JSON_VERSION_PATCH << "."
                                     << std::endl;
}