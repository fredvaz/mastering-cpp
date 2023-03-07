/*

The C++20 Masterclass Section 44: Class Templates

General Notes:
        A class template defines a family of classes.

        A class template by itself is not a type, or an object, or any other entity. No code is generated
        from a source file that contains only template definitions. In order for any code to appear
        a template must be instantiated: the template arguments must be provided so that the compiler
        can generate an actual class (or function, from a function template).

   [REF]:
    https://en.cppreference.com/w/cpp/language/class_template

*/
#include <iostream>
#include "libs/libs6/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Stream insertion operator for class templates
            * Following the previous example, we will set up a friend function for a Class template
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    BoxContainer<int> int_box;

    int_box.add(1);
    int_box.add(2);
    int_box.add(10);
    int_box.add(15);

    std::cout << "int_box: " << int_box << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
