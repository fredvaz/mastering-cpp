/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Template functions pass by Reference
*/

template <typename T>
const T &maximum(const T &a, const T &b); // Declaration by Reference

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

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

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE:  Template functions pass by Value
*/

template <typename T>
T maximum(T a, T b); // Declaration by Value

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

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

#endif // EXAMPLE_2 END

//
