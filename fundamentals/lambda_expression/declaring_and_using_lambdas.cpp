/*

The C++20 Masterclass: Lambda Expressions

General Notes:
        In C++11, Constructs a closure: an unnamed function object capable of capturing variables in scope.
        From the slides:
        A mechanism to set up anonymous functions (whiout names). Once we have them set up, we can
        either give them names and call them, or we can even get them to do things directly

        Lambda function signature: 
                           [capture list] (parameters) -> return type
                           {
                               // Function Body
                           };

    [REF] : https : //en.cppreference.com/w/cpp/language/lambda

*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: In order to be able to call the lambda funtion we must have give a name: "auto func ="
*/

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    auto func = []()
    {
        cout << "Hello World!" << endl;
    };
    // lambda funtion Call
    func();

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Declare a lambda function and call it directly
*/

int main()
{

    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    []()
    {
        cout << "Hello World!" << endl;
    }(); // Using () to call the lambda function directly

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_3

            EXAMPLE: Lambda function that takes parameters and calling it directly
*/

int main()
{
    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    [](double a, double b)
    {
        cout << "a + b : " << (a + b) << endl;
    }(10.0, 5.0); // We mus set the variables inputs here, if we have the result above

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

// #define EXAMPLE_4
#ifdef EXAMPLE_4
/*
    Notes:  #define EXAMPLE_4

            EXAMPLE: Lambda function that returns something
*/

int main()
{
    cout << "------------------------------ EXAMPLE_4 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

// #define EXAMPLE_5
#ifdef EXAMPLE_5
/*
    Notes:  #define EXAMPLE_5

            EXAMPLE: Lambda function that takes parameters and calling out
*/

int main()
{
    cout << "------------------------------ EXAMPLE_5 -------------------------------------" << endl;

    auto func = [](double a, double b)
    {
        return a + b;
    };

    auto result1 = func(10.0, 50.0);
    auto result2 = func(20.0, 30.0);

    cout << "result1 : " << result1 << endl;
    cout << "result2 : " << result2 << endl;
    cout << "direct call : " << func(5.0, 2.0) << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

// #define EXAMPLE_6
#ifdef EXAMPLE_6
/*
    Notes:  #define EXAMPLE_6

            EXAMPLE: Explicitly specify the return type : -> int
*/

int main()
{
    cout << "------------------------------ EXAMPLE_6 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END
