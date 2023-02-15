/*

The C++20 Masterclass: Using Concepts (C++20)

General Notes:
        A mechanism to place constrains on your template type parameters.

   [REF]:
   
*/
#include <iostream>
#include <concepts>

using namespace std;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

//Syntax1
/*
template <typename T>
requires std::integral<T>
T add( T a, T b){
    return a + b;
}
*/

//Syntax2
/*
template <std::integral T>
T add( T a, T b){
    return a + b;
}
*/

//Syntax3
/*
auto add(std::integral auto a , std::integral auto b){
    return a + b;
}
*/

//Syntax4
template <typename T>
T add(T a, T b) requires std::integral<T>
{
    return a + b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    char a_0{10};
    char a_1{20};

    auto result_a = add(a_0, a_1);
    std::cout << "result_a : " << static_cast<int>(result_a) << std::endl;

    int b_0{11};
    int b_1{5};
    auto result_b = add(b_0, b_1);
    std::cout << "result_b : " << result_b << std::endl;

    double c_0{11.1};
    double c_1{1.9};
    auto result_c = add(c_0, c_1);
    std::cout << "result_c : " << result_c << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//