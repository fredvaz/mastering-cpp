/*

The C++20 Masterclass: Template type deduction and explicit arguments

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <cstring>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Template type deduction and explicit arguments
*/

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int a{10};
    int b{23};
    double c{34.7};
    double d{23.4};
    string e{"hello"};
    string f{"world"};

    maximum(a, b); // int type deduced by Compiler
    maximum(c, d); // double type deduced by Compiler
    maximum(e, f); // string type deduced by Compiler

    // Explicit template arguments <double>
    auto max = maximum<double>(a, b);

    cout << "max : " << max << endl;

    auto max2 = maximum<double>(a, c); // Works even if the parameters are of different types
                                       // there is a implicit conversion from int to double
                                       // for the first parameter
    cout << "max : " << max2 << endl;

    // auto max3 = maximum(a, e); // Compiler error: can't convert std::string to double

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//