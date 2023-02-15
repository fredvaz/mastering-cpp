/*

The C++20 Masterclass: function parameter passed by Pointer

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
void say_age(int *age) // Paraneter passed by Pointer allows to modify the original variable
{                      // because it is a memory address to the original variable

    ++(*age); // * dereference operator
              // *a++; is derefencing first and incrementing but it is incrementing first
              // and then dereferencing. This is because postfix++ as a higher precedence than *
    cout << "Hello , you are " << *age << " years old! &age : " << &age << endl; // 31
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int age{30};                                                        // Local
    cout << "age (before call): " << age << " &age: " << &age << endl; // 30

    say_age(&age); // & operator to get/pass the memory address
    cout << "age (after call): " << age << " &age: " << &age << endl; // 31

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END