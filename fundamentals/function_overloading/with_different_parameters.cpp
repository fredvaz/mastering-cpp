/*

The C++20 Masterclass: Function Overloading

General Notes:
    In C++, two different functions can have the same name if their parameters are different; 
    either because they have a different number of parameters, 
    because any of their parameters are of a different type

    [REF]:
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Function Overloading is a mechanism we have in C++ to have multiple copies of the same function
           but taking different parameters
           And can't overload the return type
*/

int max(int a, int b)
{
    cout << "int overload called" << endl;
    return (a > b) ? a : b;
}

// can't overload the return type, because what makes two functions different is the different signrute name
// and parameters, a different return type of the function is not enough
// double max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

double max(double a, double b)
{   
    cout << "double overload called" << endl;
    return (a > b) ? a : b;
}

double max(int a, double b)
{   
    cout << "(int, double) overload called" << endl;
    return (a > b) ? a : b;
}

double max(double a, int b)
{   
    cout << "(double, int) overload called" << endl;
    return (a > b) ? a : b;
}

double max(double a, int b, int c)
{   
    cout << "(double, int, int) overload called" << endl;
    return (a > b) ? a : b;
}

string_view max(string_view a, string_view b)
{
    cout << "(string_view, string_view) overload called" << endl;
    return (a > b) ? a : b;
}

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

       int x{4};
   int y{9};

   double a{5.4};
   double b{7.4};

   auto result = max(x, y);
   cout << result << endl;

   double result1 = max(a, b);
   cout << result1 << endl;

   double result2 = max(a, x, y);
   cout << result2 << endl;

   cout << max("Hello", "World!") << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END