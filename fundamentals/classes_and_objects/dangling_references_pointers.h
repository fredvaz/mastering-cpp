/*

The C++20 Masterclass: Dangling references and pointers in objects

General Notes:
        We are trying to access a variable that already died after the function call.

        some compilers will let this compile with out any errors, although most self respecting modern C++
        compilers will at least throw a warning.But please know that this may also depend on the error
        levels set to your compiler. The message here is that dangling references are bad and compiler
        behavior differs. The code here is compiling,linking and running but crashing at the point where
        we call 

   [REF]:
   
*/
#include <iostream>
#include "dog_aux.cpp"

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            EXAMPLE: Danling Reference
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    Dog dog1("Rex", "Shepherd", 3);

    // Danling Reference
    // Compiler warning: reference to local variable 'dog_info' returned
    const string &str_ref = dog1.compile_dog_info();

    cout << "info: " << str_ref << endl; // We might get correct information, something wrong
    // or the program crashes

    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:  #define Test2

            EXAMPLE: Danling Pointer
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    Dog dog1("Rex", "Shepherd", 3);

    // Danling Pointer
    // Compiler warning: address of local variable 'jumps' returned 
    unsigned int *int_ptr = dog1.jumps_per_minute();

    cout << "jumps per minute: " << *int_ptr << endl; // The program crashes

    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif