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

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    // char *message{"Hello World!"}; // GCC Comipler warning
    const char *message{"Hello World!"};
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error
    std::cout << "*message : " << *message << std::endl;

    //Allow users to modify the string
    char message1[]{"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//