/*

The C++20 Masterclass: Derived classes / Inheritance and Destructors

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
#include "destructors_and_inheritance/person.cpp"
#include "destructors_and_inheritance/engineer.cpp"
#include "destructors_and_inheritance/civilengineer.cpp"

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            Default Case : Destructors are called in inverse order of the Constructors
    */
    cout << "--------------------------------------------------------------------------------" << endl;
    CivilEngineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12, "Road Strength");
    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif