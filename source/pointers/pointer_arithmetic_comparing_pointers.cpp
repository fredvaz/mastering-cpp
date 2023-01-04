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

//

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int *pointer1{&scores[0]};
    int *pointer2{&scores[8]};

    //Can also compare pointers

    //The further you go in the array, the bigger the address

    std::cout << "Comparing pointers : " << std::boolalpha << std::endl;

    std::cout << "pointer1 > pointer2 : " << (pointer1 > pointer2) << std::endl;
    std::cout << "pointer1 < pointer2 : " << (pointer1 < pointer2) << std::endl;
    std::cout << "pointer1 >= pointer2 : " << (pointer1 >= pointer2) << std::endl;
    std::cout << "pointer1 <= pointer2: " << (pointer1 <= pointer2) << std::endl;
    std::cout << "pointer1 == pointer2 : " << (pointer1 == pointer2) << std::endl;
    std::cout << "pointer1 != pointer2 : " << (pointer1 != pointer2) << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//