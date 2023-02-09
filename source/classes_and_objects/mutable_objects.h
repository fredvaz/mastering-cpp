/*

The C++20 Masterclass:

General Notes:


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

            Default Case: 
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    Dog dog1("Rex", "Shepherd", 3);
    dog1.print_info();

    for (size_t i = 0; i < 5; i++)
    {
        dog1.print_info();
    }
    
    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:  #define Test2

            Test Case: 
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif