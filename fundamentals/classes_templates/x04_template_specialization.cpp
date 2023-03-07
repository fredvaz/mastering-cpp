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
#include "libs/libs4/adder.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Class Template Specialization
            * Note: Class template specializations are FULL classes, they are not templates. If their
            * definitions show up in a header and the header is included in mutiple files, you will get
            * ODR violations
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Adder<int> adder_int;

    adder_int.do_something();
    std::cout << adder_int.add(10, 20) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Char*
    char str1[20]{"Hello"};
    char str2[]{" World!"};

    Adder<char *> adder_c_str;
    // adder_c_str.do_something();
    std::cout << adder_c_str.add(str1, str2) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
