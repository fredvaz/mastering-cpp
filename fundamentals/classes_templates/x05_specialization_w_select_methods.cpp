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
#include "libs/libs5/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Template specialization for single member functions
            * In this case, instead of specilizate all the Class we only do it for a single Class method
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Default class method

    BoxContainer<int> int_box;

    int_box.add(10);
    int_box.add(11);
    int_box.add(62);
    int_box.add(330);
    int_box.add(3);
    int_box.add(7);
    int_box.add(9);
    int_box.add(8);

    std::cout << "int_box: " << int_box << std::endl;
    std::cout << "int_box.max: " << int_box.get_max() << std::endl; //* Default class method

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Specialization class method

    BoxContainer<const char *> char_ptr_box;

    char_ptr_box.add("Apple");
    char_ptr_box.add("Kiwi");
    char_ptr_box.add("Banana");
    // char_ptr_box.add("Zeus");

    std::cout << "char_ptr_box: " << char_ptr_box << std::endl;
    std::cout << "char_ptr_box.max: " << char_ptr_box.get_max() << std::endl; //* Specialization class method

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
