/*

The C++20 Masterclass Section 42: Exception Handling

General Notes:
    Exception handling provides a way of transferring control and information from some point in the execution
    of a program to a handler associated with a point previously passed by the execution (in other words,
    exception handling transfers control up the call stack)

   [REF]:
    https://en.cppreference.com/w/cpp/language/exceptions
    https://cplusplus.com/doc/tutorial/exceptions/

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Handling Exceptions at different levels
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
