#include <iostream>
#include "my_lib.h"


void print_hello_world()
{
    std::cout << "Hello World\n";

    // Just to use command: cmake -- build . --target Library to chek the Compiler error
    // generated only with the Compilation of the Library/my_lib file
    // int x = "A"; 
}