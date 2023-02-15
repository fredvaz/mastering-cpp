/*

The C++20 Masterclass: function parameter passed by value

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

//#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

// function impplementation
void say_age(int age) // Parameter passed by valuem which is a copy of the passed parameter
{
    ++age; // This a copy, check the memory address, is different from the one in the main function
    cout << "Hello , you are " << age << " years old! &age : " << &age << endl; // 24
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int age{23};
    cout << "age (before call): " << age << " &age: " << &age << endl; // 23
    
    say_age(age);
    cout << "age (after call): " << age << " &age: " << &age << endl; // 24

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END