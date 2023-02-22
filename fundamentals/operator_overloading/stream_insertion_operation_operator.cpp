/*

The C++20 Masterclass: operator overloading -> stream insertion operation operator 

General Notes:
        Customizes the C++ operators for operands of user-defined types.
        if you make your operator a member function, the first operand has to be an 
        object of the class that you are doing the operator for.
        Refer to addition operator as member

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END