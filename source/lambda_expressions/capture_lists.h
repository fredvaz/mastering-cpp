/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test3

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Capture lists
    */
    double a{10};
    double b{20};

    auto func = [a, b]()
    {
        cout << "a + b : " << a + b << endl;
    };
    func();
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Capturing by value : what we have in the lambda function is a copy
    */
    double c{42};

    auto func = [c]()
    {
        cout << "Inner value : " << c << " | &inner : " << &c << endl;
    };
    func();

    for (size_t i{0}; i < 5; i++)
    {
       cout << "Outer value : " << c << " | &outer : " << &c << endl;
        func();
        c++;
    }
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: Capturing by reference : working on the original outside value
    */
       double c{42};

    // Adding a & to pass the variable by reference
    auto func = [&c]()
    {
        cout << "Inner value : " << c << " | &inner : " << &c << endl;
    };
    func();

    for (size_t i{0}; i < 5; i++)
    {
       cout << "Outer value : " << c << " | &outer : " << &c << endl;
        func();
        c++;
    }
}
#endif