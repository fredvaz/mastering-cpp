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
#include "libs/point4.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Static member functions
            Static member functions are not associated with any object. When called, they have no this
            pointer.
            Static member functions cannot be virtual, const, volatile, or ref-qualified.
            The address of a static member function may be stored in a regular pointer to function
            but not in a pointer to member function.
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* We can have acess to the static data member even before any object created
    //* because the the member function is detached from any object
    std::cout << "Point cout: " << Point4::get_point_count() << std::endl;

    Point4 p1;

    std::cout << "Point cout: " << Point4::get_point_count() << std::endl;

    //* To get access from the static member function we must pass a Point object as reference
    Point4 p1(3, 6);
    p1.print_info(p1);


    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
