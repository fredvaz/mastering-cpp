/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Capture lists
*/

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    double a{10};
    double b{20};

    auto func = [a, b]()
    {
        cout << "a + b : " << a + b << endl;
    };
    func();

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Capturing by value : what we have in the lambda function is a copy
*/

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: Capturing by reference : working on the original outside value
*/

//

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END