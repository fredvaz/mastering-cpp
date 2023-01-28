/*

The C++20 Masterclass: Derived classes / Classes Inheritance 

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
#include "player.cpp"
#include "nurse.cpp"
#include "engineer.cpp"
#include "civilengineer.cpp"

//#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Private members : Player Class cannot acess the private members of Class Person
    */

    Player p1("Basketball");
    p1.set_first_name("Frederico");
    p1.set_last_name("Vaz");

    cout << "player : " << p1 << endl;
}
#endif