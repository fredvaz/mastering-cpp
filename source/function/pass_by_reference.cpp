/*

The C++20 Masterclass: Pass by reference (C++)

General Notes:
        It is another technique we can use to avoid passing by a value which is going to create a copy
        And the syntax is really simple.
        We don't have to pass the address of operator.
        We don't have to go through ugly dereference like in Pointers.

        Reference vs Pointers difference:
        We cannot change the memory addres to where the Reference is pointing as in the Pointer!
        There is no method to change the memory address of a Reference.

        This exclusive to C++, in the C laguange pass by reference still means by Pointer:
        Passing by by reference refers to a method of passing the address of an argument in the calling
        function to a corresponding parameter in the called function. C onlyIn C, the corresponding 
        parameter in the called function must be declared as a pointer type. C++ only In C++, the corresponding parameter can be declared as any reference type, not just a pointer type.

   [REF]:
   
*/
#include <iostream>

using namespace std;

//

//#define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: 
*/

// function impplementation
void say_age(int &age) // Parameter passed by reference
{
    ++age;
    cout << "Hello , you are " << age << " years old! &age : " << &age << endl; // 61
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    int age{60};
    cout << "age (before call): " << age << " &age: " << &age << endl; // 60

    say_age(age);
    cout << "age (after call): " << age << " &age: " << &age << endl; // 61

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END