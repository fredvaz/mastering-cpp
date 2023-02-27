/*

The C++20 Masterclass Section 34: Static members and Const members

General Notes:
    Inside a class definition, the keyword static declares members that are not bound to class instances.
    Static members of a class are not associated with the objects of the class: they are independent variables
    with static or thread (since C++11) storage duration or regular functions.

    !e.g., they can allow to keep track how many objects for a class are created

   [REF]:
    https://en.cppreference.com/w/cpp/language/static

*/
#include <iostream>
#include "libs/cylinder.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Inine static member constants C++17
                      They can set up and initialize static variables in the class definition
                      but now we are seeing a const variable member as example
                      !example the PI number it will constant for each new object created
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Cylinder cylinder1(3.3, 10.0);

    std::cout << "Volume of cylinder : " << cylinder1.volume() << std::endl;
    std::cout << "Cylinder default color : " << Cylinder::default_color << std::endl;
    std::cout << "Cylinder default color : " << cylinder1.default_color << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//