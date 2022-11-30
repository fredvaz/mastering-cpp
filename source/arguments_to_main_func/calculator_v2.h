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
    Notes: General Calculator
    */

    double first_number{5.0};
    double second_number{33.1};
    char c{'+'};

   
    switch (c)
    {
    case '+':
        cout << first_number << " + " << second_number << " = "
                  << first_number + second_number << endl;
        break;

    case '-':
        cout << first_number << " - " << second_number << "="
                  << first_number - second_number << endl;
        break;

    case 'x':
        cout << first_number << " * " << second_number << " = "
                  << first_number * second_number << endl;
        break;

    case '/':
        cout << first_number << " / " << second_number << " = "
                  << first_number / second_number << endl;
        break;
    }
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