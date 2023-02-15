/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: C++ alternative to give alternative names to our types
    */

    using HugeInt = unsigned long long int;

    HugeInt huge_number{123378997};

    cout << "sizeof(unsigned long long int ) : " << sizeof(unsigned long long int) << endl;
    cout << "sizeof(HugeInt) : " << sizeof(HugeInt) << endl;

    cout << "huge_number : " << huge_number << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: typedef (older) syntax : Not recommended in new code
    */
    typedef unsigned long long int HugeInt;

    HugeInt huge_number{123378997};

    cout << "sizeof(unsigned long long int ) : " << sizeof(unsigned long long int) << endl;
    cout << "sizeof(HugeInt) : " << sizeof(HugeInt) << endl;

    cout << "huge_number : " << huge_number << endl;
}
#endif