/*

The C++20 Masterclass Section 43: BoxContainer clas: Practing what we know

General Notes:
        Exercise example: A Box that can contains things (int, doubles etc)

   [REF]: No

*/
#include <iostream>
#include "libs/libs1/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Constructing and destructing
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    BoxContainer box1; //* Intializes the box1 object with the DEFAULT_SIZE = 30
    // BoxContainer box1(15);
    box1.dummy_initialize();

    std::cout << "box1: " << box1 << std::endl;
    std::cout << "&box1: " << &box1 << std::endl;

    BoxContainer box2(box1);
    std::cout << "box2: " << box2 << std::endl;
    std::cout << "&box2: " << &box2 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
