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

void func_floating_point  (double d) {
	cout << "func_floating_point called..." << endl;
} 
void func_integral(int i) { 
	cout << "func_integral called..." << endl;
} 

template <typename T>
void func(T t)
{
    if constexpr(is_integral_v<T>)
        func_integral(t);
    else if constexpr(is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(is_integral_v<T> || is_floating_point_v<T>,
			"Argument must be integral or floating point");
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    func(12);

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END