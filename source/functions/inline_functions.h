/*

The C++20 Masterclass: Inline Functions

General Notes from cplusplus.com:
    The inline functions are a C++ enhancement feature to increase the execution time of a program. 
    Functions can be instructed to compiler to make them inline so that compiler can replace those 
    function definition wherever those are being called. Compiler replaces the definition of inline
    functions at compile time instead of referring function definition at runtime.
    NOTE- This is just a suggestion to compiler to make the function inline, if function is big 
    (in term of executable instruction etc) then, compiler can ignore the “inline” request and treat
    the function as normal function.

    [REF]: https://cplusplus.com/articles/2LywvCM9/
*/
#include <iostream>

#define Test1

using namespace std;

inline int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    int a{5};
    int b{8};

    cout << "max : " << max(a, b) << endl;

    // What the compiler might do to inline your function call
    std::cout << "max : ";
    if (a > b)
    {
        std::cout << a << std::endl;
    }
    else
    {
        std::cout << b << std::endl;
    }
}
#endif