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
#include "libs/point3.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Member variables of other types (Object)
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "Entering main: " << std::endl;

    Point3 point1(3.0, 3.0);
    std::cout << "distance : " << point1.length() << std::endl;

    std::cout << std::endl;
    std::cout << "Reading in the integers " << std::endl;

    std::cout << "point1.i1 : " << point1.i1.get_value() << std::endl;
    std::cout << "point1.i2 : " << point1.i2.get_value() << std::endl;
    std::cout << "Point3::i3 : " << Point3::i3.get_value() << std::endl;
    std::cout << "Point3::i4 : " << Point3::i4.get_value() << std::endl;

    point1.i1.set_value(8); //* Works, i1 is not const
    // point1.i2.set_value(10); //! Compiler error, i2 is const, can't modify it.

    std::cout << "point1.p_i5 (pointer) : " << point1.p_i5->get_value() << std::endl;

    std::cout << "Point3::i6 : " << Point3::i6.get_value() << std::endl;
    std::cout << "Point3::i7 : " << Point3::i7.get_value() << std::endl;

    Point3::i6.set_value(50);
    // Point3::i7.set_value(60); //! Compiler error : i6 is const.

    std::cout << std::endl;
    std::cout << "Leaving main" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
