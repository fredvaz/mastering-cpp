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

// The right way : return type deduction
/*
auto process_number(int value){
    if(value < 10){
        return 22; // returning int literal
    }else{
        return 55; // returning int literal
    }
}
*/

auto process_number(int value)
{
    if (value < 10)
    {
        return static_cast<double>(22); // returning int literal
    }
    else
    {
        return 33.1; // returning double literal
    }
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    auto result = process_number(17);

    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result)  : " << sizeof(result) << std::endl;
    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;
    std::cout << "sizeof(double) : " << sizeof(double) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//