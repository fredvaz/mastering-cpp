/*

The C++20 Masterclass: Section 40 : Lecture 410 : Reused Symbols in Inheritance

General Notes:


   [REF]:
   
*/
#include <iostream>
//#include "reused_symbols_in_inheritance/parent.h"
#include "reused_symbols_in_inheritance/child.h"

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            Default Case : When using the sames variables bnames in the derived and base class
            the base/parent class members will be eclipse by the ones from the derived/child class
            sp, we must use the scope operator to call a member directly from the base/parent class
    */
    cout << "--------------------------------------------------------------------------------" << endl;

    Child child(33);
    child.print_var();         // Calls the method in Child
    child.Parent::print_var(); // Calls the method in Parent,
                               // value in parent just contains junk or whatever
                               // in class initialization we did.
    cout << "--------------------------------------------------------------------------------" << endl;

    child.show_values();

    cout << "--------------------------------------------------------------------------------" << endl;
}
#endif