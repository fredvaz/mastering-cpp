/*

The C++20 Masterclass: Inline Functions

General Notes:
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

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

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

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int a{5};
    int b{8};

    cout << "max: " << max(a, b) << endl;

    // What the compiler might do to inline your function call
    cout << "max: ";
    if (a > b)
    {
        cout << a << endl;
    }
    else
    {
        cout << b << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END
