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
#include "libs/libs3/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Default values for template parameters
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Defaults to <int, 5>
    BoxContainer int_box;

    int_box.add(1);
    int_box.add(2);
    int_box.add(3);
    int_box.add(4);
    int_box.add(5);
    
    std::cout << "int_box: " << int_box << std::endl;

    //* Maximum capacity is the default: 5
    int_box.add(6);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Defaults are overriden, maximum stills = 5
    BoxContainer<double> double_box;
    double_box.add(11.1);
    std::cout << "double box: " << double_box << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Defaults are overriden
    BoxContainer<char, 10> char_box;

    char_box.add('H');
    char_box.add('e');
    char_box.add('l');
    char_box.add('l');
    char_box.add('o');
    std::cout << "char_box: " << char_box << std::endl;
    char_box.add('o');
    std::cout << "char_box: " << char_box << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
