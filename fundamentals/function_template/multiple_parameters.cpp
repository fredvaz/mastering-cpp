/*

The C++20 Masterclass: Function templates with mutiple parameters (lecture 254)
                       Template return type deduction with auto (lecture 255)

General Notes:


   [REF]: https://cplusplus.com/doc/tutorial/functions2/
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Function templates with mutiple parameters (lecture 254)
*/

/*
// Problematic : return depends on the order of the template arguments : BAD!
template <typename T , typename P> 
P   maximum( T a, P b){
    return ((a > b) ? a : b);
}
*/

template <typename ReturnType, typename T, typename P>
//template < typename T,typename ReturnType , typename P>
//template < typename T, typename P,typename ReturnType >
ReturnType maximum(T a, P b)
{
    return ((a > b) ? a : b);
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int a{5};
    double b{6.7};

    auto result = maximum<int>(a, b); // Returns, Receives all by int type
    cout << "sizeof(result): " << sizeof(result) << endl;
    cout << "result2 : " << result << endl;

    auto result2 = maximum<double, int, int>(a, b); // Returns a double, receives int, int
    cout << "sizeof(result2): " << sizeof(result2) << endl;
    cout << "result2: " << result2 << endl;

    auto result3 = maximum<double>(a, b); // Returns, Receives all by double type
    cout << "sizeof(result): " << sizeof(result3) << endl;
    cout << "result2 : " << result3 << endl;

    // auto result4 = maximum('f', '15L'); // Compiler error: does not know how to deduce the return type

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Template return type deduction with auto (lecture 255)
*/

template <typename T, typename P>
auto maximum(T a, P b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    // Largest type is going to be deduced as return type

    auto max1 = maximum('e', 33); // double return type deduced
    cout << "max1 : " << max1 << endl;
    cout << "size of max1 : " << sizeof(max1) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_2 END

//