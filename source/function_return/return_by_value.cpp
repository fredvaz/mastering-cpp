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

int sum(int a, int b)
{
    int result = a + b;
    std::cout << "In : &result(int) :  " << &result << std::endl;
    return result;
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int x{15};
    int y{9};
    int result = sum(x, y);
    std::cout << "Out : &result(int) :  " << &result << std::endl;
    std::cout << "result : " << result << std::endl;

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

std::string add_strings(std::string str1, std::string str2)
{
    std::string result = str1 + str2;
    std::cout << "In : &result(std::string) :  " << &result << std::endl;
    return result;
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    std::string in_str1{"Hello"};
    std::string in_str2{" World!"};
    std::string result_str = add_strings(in_str1, in_str2);
    std::cout << "Out : &result_str(std::string) :  " << &result_str << std::endl;
    std::cout << "result_str : " << result_str << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//
