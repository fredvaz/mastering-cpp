/*

The C++20 Masterclass: Default Arguments in Template functions

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

            EXAMPLE: Default Arguments in Template functions
*/

template <typename ReturnType = double, typename T, typename P> // = double set as default
ReturnType maximum(T a, P b)
{
    return (a > b) ? a : b;
}

template <typename T, typename P, typename ReturnType = double> // = double set as default
ReturnType minimum(T a, P b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    double a{16.5};
    double b{9.5};

    auto result = minimum<int, double, int>(a, b); // the default here is overload by the explicit int type declared
    cout << "result: " << result << endl;
    cout << "sizeof(result): " << sizeof(result) << endl; // 4

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//