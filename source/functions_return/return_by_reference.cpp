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

int &max_return_reference(int &a, int &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int x{14};
    int y{9};
    int &ref_max = max_return_reference(x, y); // Reference
    int val = max_return_reference(x, y);      // Copy
    std::cout << "ref_max : " << ref_max << std::endl;
    std::cout << "val : " << val << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    ref_max++;
    std::cout << "----- " << std::endl;
    std::cout << "ref_max : " << ref_max << std::endl; // 15
    std::cout << "val : " << val << std::endl;         // 14
    std::cout << "x : " << x << std::endl;             // 15
    std::cout << "y : " << y << std::endl;             // 9

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: 
*/

int &sum(int &a, int &b)
{
    int result = a + b;
    return result; //  Compiler warning: reference to local variable 'result' returned
                   // Reference to local variable returned
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    int x{14};
    int y{9};
    int &result = sum(x, y); // Reference
    std::cout << "result : " << result << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: 
*/

int &max_input_by_value(int a, int b)
{
    if (a > b)
    {
        return a; // Compiler warning: Reference to local variable returned
    }
    else
    {
        return b; // Compiler warning: Reference to local variable returned
    }
}

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    int x{14};
    int y{9};
    int &result = max_input_by_value(x, y); // Reference
    std::cout << "result : " << result << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//
