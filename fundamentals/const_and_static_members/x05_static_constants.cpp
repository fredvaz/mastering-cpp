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

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Static constant pre C++17
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //TODO:

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//