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
#include <cmath>
#include "libs/point.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Inline static members variables C++17
                      They can set up and initialize static variables in the class definition
                      different from the previous example
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // Print the point count in our program
    // std::cout << "Point count: " << Point::m_point_count << std::endl; //! IF declared public member

    Point p1(5, 5);
    Point p2(8, 8);

    p1.print_info(); // We see that each variables live a different memory address for each Object
    p2.print_info();

    std::cout << "Point count: " << p1.get_point_count() << std::endl; // 2 Point objects

    Point points[]{Point(1, 1), Point(2, 2), Point(3, 3)};

    std::cout << "Point count: " << p1.get_point_count() << std::endl; // 5 Point objects

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//