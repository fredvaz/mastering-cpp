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
#include "libs/cylinder2.hpp"
#include "libs/bird.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Static constant pre C++17
            !Only integral types in an enum are initializable from the class declaration
            !others have to be initialized in some cpp file

            !Static initialization order is not guaranteed.
            if have static variables that depend on the static variables, you may get a crashes for your app
            if the initialization order does not work in your favor.
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Cylinder2 cylinder(3.3, 10.0);

    std::cout << "Volume of cylinder : " << cylinder.volume() << std::endl;
    std::cout << "Cylinder2 default color: " << Cylinder2::default_color << std::endl;
    std::cout << "Cylinder2 default color: " << cylinder.default_color << std::endl;

    std::cout << std::endl;
    std::cout << "Other constants" << std::endl;
    std::cout << "Int constant: " << Cylinder2::INT_CONSTANT << std::endl;
    std::cout << "Color(enum) constant: " << Cylinder2::COLOR_CONSTANT << std::endl;
    std::cout << "Char ptr constant: " << Cylinder2::CHAR_PTR_CONSTANT << std::endl;
    std::cout << "arr[2]: " << Cylinder2::INT_ARRAY_CONSTANT[2] << std::endl;
    std::cout << "float constant: " << Cylinder2::FLOAT_CONSTANT << std::endl;
    std::cout << "str_arr[1]: " << Cylinder2::STRING_ARRAY_CONSTANT[1] << std::endl;

    std::cout << std::endl;
    std::cout << "Can't modify those static constants" << std::endl;
    // Cylinder2::INT_CONSTANT = 6; //! Compiler error.

    std::cout << std::endl;
    std::cout << "raw constants" << std::endl;
    std::cout << "WEIRD_FLOAT: " << cylinder.WEIRD_FLOAT << std::endl;
    std::cout << "WEIRD_C_STRING: " << cylinder.WEIRD_C_STRING << std::endl;
    std::cout << "WEIRD_INT_ARRAY[3]: " << cylinder.WEIRD_INT_ARRAY_CONSTANT[3] << std::endl;
    std::cout << std::endl;

    std::cout << "Constant initialized with other constant" << std::endl;
    std::cout << "BIRD_WEIGHT_CONSTANT : " << Bird::BIRD_WEIGHT_CONSTANT << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//