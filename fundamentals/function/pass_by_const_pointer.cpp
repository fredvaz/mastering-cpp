/*

The C++20 Masterclass: function parameter passed by Const Pointer

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
void say_age(const int *age) // Paraneter passed by Const Pointer NOT allows to modify the original variable
{                            // value but as we are acessing the variable value directly in the memory and not
                             // creating a copy in the memory, we are increasing the performance and spare
                             // the availabe memory

    //++(*age); // Compiler error: increment of read-only location '* age'
    cout << "Hello , you are " << *age << " years old! &age : " << &age << endl; // 40
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int age{40};                                                       // Local
    cout << "age (before call): " << age << " &age: " << &age << endl; // 40

    say_age(&age);                                                    // & operator to get/pass the memory address
    cout << "age (after call): " << age << " &age: " << &age << endl; // 40

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_1 END