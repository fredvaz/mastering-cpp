/*

The C++20 Masterclass: Decltype and trailing return types

General Notes:
        Inspects the declared type of an entity or the type and value category of an expression. (C++11)

   [REF]: https://en.cppreference.com/w/cpp/language/decltype
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Decltype and trailing return types
*/

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    // declytpe
    int a{9};
    double b{15.8};

    cout << "size : " << sizeof(decltype((a > b) ? a : b)) << endl; // 4

    decltype((a > b) ? a : b) c{7}; // Declaring other variables through declytype

    cout << "c: " << c << endl;
    cout << "sizeof(c): " << sizeof(c) << endl; // 4

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: 
*/

// Declaration
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b);

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    // declytpe
    int a{9};
    double b{15.8};

    auto result = maximum(a, b);
    cout << "result: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

// Definition
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b)
{
    return (a > b) ? a : b;
}

#endif // EXAMPLE_2 END

//