/*

The C++20 Masterclass: Constexpr functions

General Notes:
        The constexpr specifier declares that it is possible to evaluate the value of the function or variable
        at compile time. Such variables and functions can then be used where only compile time constant
        expressions are allowed (provided that appropriate function arguments are given).

   [REF]: https://en.cppreference.com/w/cpp/language/constexpr
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

// Marking a function as constexpr gives it the potential
// to be evaluated at compile time
constexpr int get_value(int multiplier)
{
    return 3 * multiplier;
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    /*
        For the evaluation to take place at compile time, we have 
        to remember to store the return value in a constexpr result variable
    */
    constexpr int result = get_value(4); // Compile time given the literal 4
    std::cout << "result : " << result << std::endl;

    
    int some_var{5}; // Run time variable
    int result = get_value(some_var); // Run time
    std::cout << "result : " << result << std::endl;
    

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END
