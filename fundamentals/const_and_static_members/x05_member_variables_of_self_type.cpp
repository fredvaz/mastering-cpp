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
#include "libs/point2.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Member variables of self type
            ! We cannot declare member variables of the same type of the class in the class declaration
            ! We must create a Pointer of the type class, that will be initialized later
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //! Study Case when we intialize the Pointer dynamically it will call the Point() constructor segmentation fault
    // Point2 p1;

    Point2 p1(3, 3);

    //* If we want to intialize our member variable "p_m_point4" as Point Class type
    p1.initialize_pointer(5, 5);

    p1.print_info();
    p1.p_m_point4->print_info(); // p_m_point is a Class Point 2 object too

    //* Another way: Initialize the member variables in a cpp file
    p1.m_point4.print_info();
    p1.m_point5.print_info();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
