#include <iostream>

#include "my_lib.h"

// Add the configured files with the versions
#include "config.hpp"

// Adds the Git submodule
#include <nlohmann/json.hpp>


// Adds the Fetched Libraries in our code
#include <cxxopts.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
 

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

    std::cout << "FMT Lib Version: " << FMT_VERSION
                                      << std::endl;

    std::cout << "CXXOPTS Lib Version: " << CXXOPTS__VERSION_MAJOR << "."
                                      << CXXOPTS__VERSION_MINOR << "."
                                      << CXXOPTS__VERSION_PATCH << "."
                                      << std::endl;

    std::cout << "SPDLOG Lib Version: " << SPDLOG_VER_MAJOR << "."
                                      << SPDLOG_VER_MINOR << "."
                                      << SPDLOG_VER_PATCH << "."
                                      << std::endl;                                     


    print_hello_world();

    return 0;
}

