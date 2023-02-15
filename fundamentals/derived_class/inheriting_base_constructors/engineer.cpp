/*

The C++20 Masterclass: Base Class acess specifiers : Private inheritance

General Notes:
        When a class uses private member access specifier to derive from a base, all public
        and protected members of the base class are accessible as private members of the
        derived class (private members of the base are never accessible unless friended).

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#include "person.h"
#include "engineer.h"
#include <iostream>

/* Engineer::Engineer()
{
    cout << "Default constructor for Engineer called..." << endl;
} 
*/
#ifdef Test3
Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count{contract_count_param}
{
    cout << "Custom constructor for Engineer called..." << endl;
}
#endif
/* 
Engineer::Engineer(const Engineer &source)
    : Person(source), contract_count{source.contract_count}
{
    cout << "Copy Custom constructor for Engineer called..." << endl;
}
*/

std::ostream &operator<<(std::ostream &out, const Engineer &operand)
{
    out << "Engineer [Full name : " << operand.m_full_name
        << ", age : " << operand.m_age
        << ", address : " << operand.get_address()
        << ", contract_count : " << operand.contract_count << "]";

    operand.m_age;

    return out;
}

Engineer::~Engineer()
{
}