/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test2

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Capture all parameters inside the lambda function
    by value using the = operator
    */
    int c{42};

    auto func = [=]()
    {
        std::cout << "Inner value : " << c << std::endl;
        // Note: values captured by value can't be modified in the body of the lambda function by default.
    };

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "Outer value : " << c << std::endl;
        func();
        c++;
    }
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Capturing all parameters by reference using the & operator
    */
       int c{42};
       int d{5};

    auto func = [&]()
    {
        std::cout << "Inner value (c) : " << c << std::endl;
        std::cout << "Inner value (d) : " << d << std::endl;
    };

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << "Outer value (c) : " << c << std::endl;
        func();
        c++;
    }
}
#endif