/*

The C++20 Masterclass: decltype auto

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

            EXAMPLE: decltype auto
*/

// Using the decltype auto we can only do the function declaration
// since the compiler will not look the after the main
template <typename T, typename P>
decltype(auto) maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ USE_USE_1 -------------------------------------" << endl;

    int x{7};
    double y{45.9};

    auto result = maximum(x, y);
    cout << "max : " << result << endl;
    cout << "sizeof(result) : " << sizeof(result) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//