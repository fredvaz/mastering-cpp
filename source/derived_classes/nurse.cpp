/*

The C++20 Masterclass: Base Class acess specifiers : Protected inheritance

General Notes:
        When a class uses protected member access specifier to derive from a base
        all public and protected members of the base class are accessible as
        protected members of the derived class (private members of the base are never
        accessible unless friended)

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#include "person.h"
#include "nurse.h"
#include <iostream>

Nurse::Nurse()
{
}

std::ostream &operator<<(std::ostream &out, const Nurse &operand)
{
    out << "Nurse [Full name : " << operand.m_full_name
        << ", age : " << operand.m_age
        << ", address : " << operand.get_address()
        << ", practice certificate id : "
        << operand.practice_certificate_id << "]";

    return out;
}

Nurse::~Nurse()
{
}