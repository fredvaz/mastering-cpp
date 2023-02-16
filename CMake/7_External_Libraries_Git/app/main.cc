#include <iostream>

#include "my_lib.h"

// Add the configured files with the versions
#include "config.hpp"

// Adds the Git submodule
#include <nlohmann/json.hpp>

// Code example to be compiled using CMake Tool

int main()
{

    // Call the project configuration
    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    std::cout << "JSON Lib Version: " << NLOHMANN_JSON_VERSION_MAJOR << "."
                                      << NLOHMANN_JSON_VERSION_MINOR << "."
                                      << NLOHMANN_JSON_VERSION_PATCH << "."
                                      << std::endl;

    print_hello_world();

    return 0;
}

