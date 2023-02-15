/*

The C++20 Masterclass: function parameter passed by Const Pointer to Const

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

int dog_count{2};

// function impplementation
void say_age(const int *const age) // Paraneter passed by Const Pointer NOT allows to modify the original variable
{                                  // neither allows to modiy the memory address where the variables lives

    //++(*age); // Compiler error: increment of read-only location '* age'
    cout << "Hello , you are " << *age << " years old! &age : " << &age << endl; //50

    //age = &dog_count; // Changing the memory addres of age to the dog_count is not allowed
                      // aka, pointing age Pointer to dog_count memory address
                      // Compiler error: assignment of read-only parameter 'age'

}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    int age{50};                                                       // Local
    cout << "age (before call): " << age << " &age: " << &age << endl; // 50

    say_age(&age);                                                    // & operator to get/pass the memory address
    cout << "age (after call): " << age << " &age: " << &age << endl; // 50

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END