/*

The C++20 Masterclass Section 46: Function Like Entities

General Notes:
        * Things that can work as functions in C++
        * Taking input
        * Doing something in the function body
        * Returning values
        Callback functions are heavily used in event based programming like Graphcal User Interfaces
        but that's out of scope for this course


   [REF]:

*/
#include <iostream>
#include "libs/libs1/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Callback functions
            * A callback function is a function whose function pointer may be passed to another function
            * as a parameter, and be called somewhere in the body of that function.
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
