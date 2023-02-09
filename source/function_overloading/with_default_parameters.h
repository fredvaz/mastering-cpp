/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

// Functions declaration - Two valid functions overloads because they ay different type of parameters
void print_age(int age = 33);
void print_age(long int age = 44);

#ifdef Test1
void test1()
{
    /*
    Notes:
    */

    // When calling the funtion in this way whitout parameters,
    //  the Compiler will not know which overload should take
    print_age();

    // Calling the first function overload
    int age{67};

    print_age(age);
}
#endif