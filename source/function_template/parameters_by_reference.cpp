/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Template functions pass by Reference
*/

template <typename T>
const T &maximum(const T &a, const T &b); // Declaration by Reference

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    double a{23.5};
    double b{51.2};

    cout << "Out - &a: " << &a << endl; // 0xd23bfffd80
    auto result = maximum(a, b);
    cout << "Out - &a: " << &a << endl; // 0xd23bfffd80

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

// Definition or Implementation
template <typename T>
const T &maximum(const T &a, const T &b)
{
    cout << "In - &a: " << &a << endl; // 0xd23bfffd80
    return (a > b) ? a : b;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case:  Template functions pass by Value
*/

template <typename T>
T maximum(T a, T b); // Declaration by Value

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    double a{23.5};
    double b{51.2};

    cout << "Out - &a: " << &a << endl; // 0xc2349ffb68
    auto result = maximum(a, b);
    cout << "Out - &a: " << &a << endl; // 0xc2349ffb68

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

template <typename T>
T maximum(T a, T b)
{
    cout << "In - &a: " << &a << endl; // 0xc2349ffb40
    return (a > b) ? a : b;
}

#endif // TEST_CASE_2 END

//
