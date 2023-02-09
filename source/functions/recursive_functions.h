/*

The C++20 Masterclass: Recursive Functions

General Notes from cplusplus.com:
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

#define Test1

using namespace std;

size_t sum_up_to_zero(size_t value)
{
    if (value != 0)
        return value + sum_up_to_zero(value - 1);
    return 0;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    cout << "result : " << sum_up_to_zero(10) << endl;
}
#endif
