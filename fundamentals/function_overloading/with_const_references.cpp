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

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int a{45};
    int b{85};

    int result = max(a, b);
    cout << "result : " << result << endl;

    // To force the call of the second function overload we must declare const reference variables
    const int &ref_a = a;
    const int &ref_b = b;

    int result1 = max(ref_a, ref_b);

    cout << "result1 : " << result1 << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END