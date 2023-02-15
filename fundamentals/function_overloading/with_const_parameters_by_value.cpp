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

            EXAMPLE: 
*/

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }

// Constant overloads - Because the function below althiug has the variables as const
// they are not changed in the scope function. Therefore, the compiler is going to
// think this two functions are equivalent
// int max(const int a, const int b)
// {
//     return (a > b) ? a : b;
// }

// int max(int a, int b)
// {
//     ++a;
//     return (a > b) ? a : b;
// }

// Declaration
int max(int a, int b);

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

int max(const int a, const int b)
{
    //++a; // It wil generate a Compiler error because the var is not allowed to be modified
    return (a > b) ? a : b;
}

#endif // EXAMPLE_END