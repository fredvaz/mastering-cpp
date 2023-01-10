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

            Test Case: 
*/

auto &max(int &a, int &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b; // Will return a copy.
    }
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int x{10};
    int y{45};

    int &result = max(x, y); // Error : Can not treat return value as a reference
                             // It's jut a bare separate variable with a value inside.

    //int result = max(x,y); // A copy of the max is returned

    ++result;

    std::cout << "x :" << x << std::endl;            // 10
    std::cout << "y :" << y << std::endl;            // 46
    std::cout << "result : " << result << std::endl; // 46
    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Function definition with return type deduction
*/

auto max(int &a, int &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b; // Will return a copy.
    }
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    int x{5};
    int y{9};

    int int_val = max(x, y);

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//