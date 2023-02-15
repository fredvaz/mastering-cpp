/*

The C++20 Masterclass: Consteval functions

General Notes:
        The consteval specifier declares a function or function template to be an immediate function
        that is, every potentially-evaluated call to the function must (directly or indirectly) produce
        a compile time constant expression.

   [REF]: https://en.cppreference.com/w/cpp/language/consteval
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Consteval functions
*/

// Evaluate this function at compile time. If you can't
// do that throw a compiler error
consteval int get_value(int multiplier)
{
    return 3 * multiplier;
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int result = get_value(4); // Compile time

    // int some_var{5}; // Run time variable
    // result = get_value(some_var); // Run time, as the function is marked as consteval it will give us a
                                     // Compiler error: the value of 'some_var' is not usable in a constant expression

    const int some_var{5}; //  This time the code works jut fine because all the arguments are constants that can be evaluated at compile time.
    result = get_value(some_var);

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END