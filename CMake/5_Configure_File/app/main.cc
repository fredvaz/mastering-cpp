#include <iostream>

#include "my_lib.h"

// Add the configured files with the versions
#include "config.hpp"

// Code example to be compiled using CMake Tool

int main()
{

    // Call the project configuration
    std::cout << project_name << std::endl;
    std::cout << project_version << std::endl;

    print_hello_world();

    return 0;
}

