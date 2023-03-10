/*

The C++20 Masterclass Section 45: Move Semantics (C++11)

General Notes:
    A set of features that were introduced in C++11 tom it easy to use temporary variables in C++
    and avoid unnecessary copies

    So, basically the Pointer to the final data will Pointer to the Pointer of temporary data instead
    of creating a copyig the temporary data to a new memory location for the final data

   [REF]:

*/
#include <iostream>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Ravlue references
            * This a mechism in C++ to extend the lifetime of temporary values
            * When an rvalue reference is bound to an rvalue, the life of the rvalue is extended
            * and we can manipulate it through the rvalue reference
*/

double add(double a, double b)
{
    return a + b;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    int x{5};
    int y{10};

    int &&result = x + y;

    double &&outcome = add(10.1, 20.2);

    std::cout << "result: " << result << std::endl;
    std::cout << "outcome: " << outcome << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
