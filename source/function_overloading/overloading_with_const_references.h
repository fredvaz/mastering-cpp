/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

int max(int &a, int &b)
{
    cout << "max with int & called" << endl;
    // We can change the a and b variables through the reference
    // This change will be visible outside the function
    a = 200; 
    return (a > b) ? a : b;
}

int max(const int &a, const int &b)
{
    cout << "max with the const int & called" << endl;

    // We can NOT change the a an b variables through the reference 
    // The below statement will give a Compiler Error
    // a = 200;
    return (a > b) ? a : b;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    int a{45};
    int b{85};

    int result = max(a, b);
    cout << "result : " << result << endl;

    // To force the call of the second function overload we must declare const reference variables
    const int &ref_a = a;
    const int &ref_b = b;

    int result1 = max(ref_a, ref_b);

    cout << "result1 : " << result1 << endl;
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