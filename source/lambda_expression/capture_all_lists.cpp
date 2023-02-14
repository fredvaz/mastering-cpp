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

            Test Case: Capture all parameters inside the lambda function by value using the = operator
*/

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

#define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Capturing all parameters by reference using the & operator
*/

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

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

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END