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

// Functions declaration - Two valid functions overloads because they ay different type of parameters
void print_age(int age = 33);
void print_age(long int age = 44);

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    // When calling the funtion in this way whitout parameters,
    // the Compiler will not know which overload should take
    // print_age();

    // Calling the first function overload
    int age{67};

    print_age(age);

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

void print_age(int age)
{
    cout << "Your age is (int version) : " << age << endl;
}

void print_age(long int age)
{
    cout << "Your age is (long int version) : " << age << endl;
}

#endif // Test Case END