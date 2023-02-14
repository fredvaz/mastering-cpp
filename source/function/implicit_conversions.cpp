/*

The C++20 Masterclass: Implicit Conversions passed to function parameters

General Notes:
        These are conversions that the computer is going to insert if you pass a type that is different
        from what the function actually takes and if the conversion fails, you're going to get a compiler error.

   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Implicit Conversions passed to function parameters
*/

// Print sum function expects two int types
void print_sum(int a, int b)
{

    int sum = a + b;
    cout << "sizeof(a): " << sizeof(a) << endl;
    cout << "sizeof(b): " << sizeof(b) << endl;
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "sum: " << sum << endl;
    cout << endl;
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    double a{4.5};
    double b{7.8};
    // double a{"4.5"}; // Compiler error: cannot convert 'const char*' to 'double' in initialization
    // double b{"7.8"};

    print_sum(a, b); // Print sum function expects two int types
                     // therefore the Compiler will perform a implicit conversion from the double to int type
                     // but we will losse the decimal part of the double types

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END