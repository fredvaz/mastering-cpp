/*

The C++20 Masterclass: Recursive Functions

General Notes:
    Recursion is the process where a function is called itself 
    but stack frame will be out of limit because function call 
    will be infinite times. So a termination condition is mandatory 
    to a recursion.

    Many complex problem can be solved by recursion in a simple code. 
    But it's too much costly than iterative. because in every recursion 
    call one stack frame will formed.

   [REF]: https://cplusplus.com/articles/zAUq5Di1/
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

size_t sum_up_to_zero(size_t value)
{
    if (value != 0)
        return value + sum_up_to_zero(value - 1);
    return 0;
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    cout << "result : " << sum_up_to_zero(10) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Coding exercise 37  
*/

unsigned int factorial(unsigned int n)
{
    if (n > 1) // On the recursive functions is MANDATORY to have a STOP CONDITION if not it will run forever
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{

    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    unsigned int n{5};

    cout << n << "! (factorial) : " << factorial(5) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END