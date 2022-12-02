/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

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

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
}
#endif