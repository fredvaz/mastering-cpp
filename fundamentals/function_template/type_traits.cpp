/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <type_traits>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

template <typename T>
void print_number(T n)
{
    static_assert(is_integral_v<T>, "print_number() can only be called with integral types");
    cout << "number : " << n << endl;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    cout << boolalpha;
    cout << "is_integral<int> : " << is_integral<int>::value << endl;
    cout << "is_floating_point<int> : " << is_floating_point<int>::value << endl;
    cout << "-------------" << endl;
    cout << "is_integral_v<int> : " << is_integral_v<int> << endl;
    cout << "is_floating_point_v<int> : " << is_floating_point_v<int> << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END