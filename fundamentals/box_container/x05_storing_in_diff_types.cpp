/*

The C++20 Masterclass Section 43: BoxContainer clas: Practing what we know

General Notes:
        Exercise example: A Box that can contains things (int, doubles etc)

   [REF]: No

*/
#include <iostream>
#include "libs/libs5/intcontainer.hpp"
#include "libs/libs5/doublecontainer.hpp"
#include "libs/libs5/charcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Storing in different types (Changing the alias type container)
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    DoubleContainer double_box1;
    double_box1.add(11.2);
    double_box1.add(33.5);

    std::cout << "double_box1: " << double_box1 << std::endl;

    IntContainer int_box1;
    int_box1.add(10);
    int_box1.add(20);

    std::cout << "int_box1: " << int_box1 << std::endl;

    CharContainer char_box1;
    char_box1.add('H');
    char_box1.add('e');
    char_box1.add('l');
    char_box1.add('l');
    char_box1.add('o');

    std::cout << "char_box1: " << char_box1 << std::endl;

    char_box1.remove_all('l');
    std::cout << "char_box1: " << char_box1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
