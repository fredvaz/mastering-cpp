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

#ifdef Test2
void test2()
{
    /*
    Notes: Protected members : Only Player Class can acess the private members of Class Person
    */

    Player p1("Basketball", "Frederico", "Vaz");
    // Now we don't need acess ther member variables using the methods functions because
    // the Player casses has protected access to he member variable of the Person Class
    cout << "player : " << p1 << endl;

    // Still we cannot direct acess externally the private members of the Base Class Person
    //p1.first_name = "Daniel"; // Compiler Error
}
#endif
