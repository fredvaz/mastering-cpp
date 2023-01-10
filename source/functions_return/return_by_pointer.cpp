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

int *max_return_pointer(int *a, int *b)
{
    if (*a > *b)
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

    int x{56};
    int y{45};
    int *p_max = max_return_pointer(&x, &y);
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

    ++(*p_max);
    std::cout << "-----" << std::endl;
    std::cout << "x : " << x << std::endl;
    std::cout << "y : " << y << std::endl;
    std::cout << "*p_max : " << *p_max << std::endl;

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

int *sum(int *a, int *b)
{
    int result = *a + *b;
    return &result; // Pointer to local variable returned, the program it will crash
                    // Compiler warning: address of local variable 'result' returned
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    int x{56};
    int y{45};
    int *p_sum = sum(&x, &y);
    std::cout << *p_sum << std::endl;

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

int *max_input_by_value(int a, int b)
{
    if (a > b)
    {
        return &a; // Pointer to local variable returned, the program it will crash
    }
    else
    {
        return &b; // Pointer to local variable returned, the program it will crash
    }
}

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    int x{56};
    int y{45};
    int *p_sum = max_input_by_value(x, y);
    std::cout << *p_sum << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//