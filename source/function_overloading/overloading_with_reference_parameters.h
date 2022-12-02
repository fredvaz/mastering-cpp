/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>
#include <string>

#define Test1

using namespace std;

// Ambigous calls
void say_my_name(const string &name)
{
    cout << "Your name is (ref) : " << name << endl;
}

void say_my_name(string name)
{
    cout << "Your name is (non ref) : " << name << endl;
}

// Implicit conversions with references
// double max(double a, double b)
// {
//     cout << "double max called" << endl;
//     return (a > b) ? a : b;
// }

// int &max(int &a, int &b) // Do again after the Functions Chapter
const int &max(const int &a, const int &b)
{
    cout << "int max called" << endl;
    return (a > b) ? a : b;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    char a{6};
    char b{9};

    auto result = max(a, b); // It will work only with the const references
    cout << "result : " << result << endl;

    // Potential solution : Simple Cast
    // int temp_a{static_cast<int>(a)};
    // int temp_b{static_cast<int>(b)};

    // auto result1 = max(temp_a, temp_b);
    // cout << "result1 : " << result1 << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
   string name{"John"};

   say_my_name(name);

   say_my_name("John");
}
#endif