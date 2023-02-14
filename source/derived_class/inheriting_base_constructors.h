/*

The C++20 Masterclass: Derived classes / Inheriting Base Constructors

General Notes:
        Any class type (whether declared with class-key class or struct) may be declared
        as derived from one or more base classes which, in turn, may be derived from their
        own base classes, forming an inheritance hierarchy.

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
    https://en.cppreference.com/book/intro/inheritance
    https://cplusplus.com/doc/tutorial/inheritance/

*/
#include <iostream>
#include "inheriting_base_constructors/person.cpp"
#include "inheriting_base_constructors/engineer.cpp"

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            Default Case : Inheriting Default Base Constructor
    */
    Engineer eng1; // Default Constructor call

    cout << "eng1 : " << eng1 << endl;

}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:  #define Test2

            Test Case : Inheriting Custom Person Base Constructor
    */
    Engineer eng1("Daniel Gray", 23, "Coimbra PT"); // It will call Custom Person Constructor inherited
                                                    // and with the Engineer member variables

    cout << "eng1 : " << eng1 << endl;

    // Another Test Case: Compiler Error this Constructor is not declared in Person neither in Engineer Class
    //Engineer eng2("Daniel Gray", 23, "Coimbra PT", 4); 
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: #define Test3
           
           Test Case : Uses the Custom Engineer Constructor 
    */
    Engineer eng1("Daniel Gray", 23, "Coimbra PT", 4); // It will call Custom Engineer Constructor

    cout << "eng1 : " << eng1 << endl;
}
#endif