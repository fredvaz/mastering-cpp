/*

The C++20 Masterclass: Lambda Expressions

General Notes:
        In C++11, Constructs a closure: an unnamed function object capable of capturing variables in scope.
        From the slides:
        A mechanism to set up anonymous functions (whiout names). Once we have them set up, we can
        either give them names and call them, or we can even get them to do things directly

   [REF]: https://en.cppreference.com/w/cpp/language/lambda
*/

#include <iostream>

#define Test6

using namespace std;

/*
Lambda function signature : 
                           [capture list] (parameters) -> return type
                           {
                               // Function Body
                           };

*/

#ifdef Test1
void test1()
{
    /*
    Notes: In order to be able to call the lambda funtion we must have give a name: "auto func ="
    */

    auto func = []()
    {
        cout << "Hello World!" << endl;
    };
    // lambda funtion Call
    func();
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Declare a lambda function and call it directly
    */
    []()
    {
        cout << "Hello World!" << endl;
    }(); // Using () to call the lambda function directly
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes Lambda function that takes parameters and calling it directly
    */
    [](double a, double b)
    {
        cout << "a + b : " << (a + b) << endl;
    }(10.0, 5.0); // We mus set the variables inputs here, if we have the result above
}
#endif

#ifdef Test4
void test4()
{
    /*
    Notes: Lambda function that returns something
    */
    auto result = [](double a, double b)
    {
        return a + b;
    }(10.0, 20.0); // Calling it directly with input parameters

    cout << "result1 : " << result << endl;
    // OR
    cout << "result2 : " << [](double a, double b)
    {
        return a + b;
    }(20.0, 20.0)
         << endl;
}
#endif

#ifdef Test5
void test5()
{
    /*
    Notes: Lambda function that takes parameters and calling out
    */
    auto func = [](double a, double b)
    {
        return a + b;
    };

    auto result1 = func(10.0, 50.0);
    auto result2 = func(20.0, 30.0);

    cout << "result1 : " << result1 << endl;
    cout << "result2 : " << result2 << endl;
    cout << "direct call : " << func(5.0, 2.0) << endl;
}
#endif

#ifdef Test6
void test6()
{
    /*
    Notes: Explicitly specify the return type : -> int
    */
    auto func1 = [](double a, double b) -> int
    {
        return a + b;
    };

    // Not declaring the return type
    auto func2 = [](double a, double b)
    {
        return a + b;
    };

    double a{6.9};
    double b{3.5};

    auto result1 = func1(a, b);
    auto result2 = func2(a, b);

    cout << "result1 : " << result1 << endl;
    cout << "sizeof(result1) : " << sizeof(result1) << endl; // The return type int has 4 bytes
    cout << "result2 : " << result2 << endl;
    cout << "sizeof(result2) : " << sizeof(result2) << endl;
}
#endif