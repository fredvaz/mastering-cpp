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

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: In order to be able to call the lambda funtion we must have give a name: "auto func ="
*/

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    auto func = []()
    {
        cout << "Hello World!" << endl;
    };
    // lambda funtion Call
    func();

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Declare a lambda function and call it directly
*/

int main()
{

    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    []()
    {
        cout << "Hello World!" << endl;
    }(); // Using () to call the lambda function directly

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: Lambda function that takes parameters and calling it directly
*/

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    [](double a, double b)
    {
        cout << "a + b : " << (a + b) << endl;
    }(10.0, 5.0); // We mus set the variables inputs here, if we have the result above

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

// #define TEST_CASE_4
#ifdef TEST_CASE_4
/*
    Notes:  #define TEST_CASE_4

            Test Case: Lambda function that returns something
*/

int main()
{
    cout << "------------------------------ Test Case 4 -------------------------------------" << endl;

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

#endif // TEST_CASE_N END

//

// #define TEST_CASE_5
#ifdef TEST_CASE_5
/*
    Notes:  #define TEST_CASE_5

            Test Case: Lambda function that takes parameters and calling out
*/

int main()
{
    cout << "------------------------------ Test Case 5 -------------------------------------" << endl;

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

#endif // TEST_CASE_N END

// #define TEST_CASE_6
#ifdef TEST_CASE_6
/*
    Notes:  #define TEST_CASE_6

            Test Case: Explicitly specify the return type : -> int
*/

int main()
{
    cout << "------------------------------ Test Case 6 -------------------------------------" << endl;

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

#endif // TEST_CASE_N END
