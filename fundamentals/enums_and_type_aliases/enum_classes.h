/*

The C++20 Masterclass: Enum Classes

    - Enum classes should be properly prefixed with a scope resolution operator for them to be recognized
      by the compiler 
    - Enum classes can't implicitly convert to/from anything, including other enum classes
    - Enum classes can't implicitly convert to something directly printable through std::cout

*/

#include <iostream>

#define Test2

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Enum and Type Alias are a facility we ahve in C++ to represent a range 
           of values, e.g., represent year months
    */

    enum class Month // default type associated with enum classes with C++ is int
    {
        Jan,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct,
        Nov,
        Dec
    }; // Enumerators are the data inside the enum class

    Month month {Month::Jan}; // Month:: Enum classes should be properly prefixed with
                              // a scope resolution operator for them to be recognized by the compiler 

    // Because each enumeration is represented by an integral value unde the hood
    // we can print the iterator for each one by the following:
    cout << "month : " << static_cast<int>(month) << endl;
    // The default type associated with enum classes with C++ is int
    cout << "sizeof(month) : " << sizeof(month) << endl;

    // Note: Enum classes can't implicitly convert to something directly printable 
    // through std::cout. The code will just throw some compiler error.
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */

    // Customize integral values
    // Multiple enumerators for the same value
    // Enumerators in terms of others
    // Custom Type: enum class Month : char
    // unsigned char : 0 ~ 255
    enum class Month : unsigned char
    {
        Jan = 1,
        January = Jan,
        Feb,
        Mar,
        Apr,
        May,
        Jun,
        Jul,
        Aug,
        Sep,
        Oct = 100,
        Nov,
        Dec
    };

    Month month {Month::Dec};

    cout << "month : " << static_cast<int>(month) << endl;
    // The default type associated with enum classes with C++ is int
    cout << "sizeof(month) : " << sizeof(month) << endl;
}
#endif