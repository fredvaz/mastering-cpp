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

Engineer::Engineer()
{
    cout << "Default constructor for Engineer called..." << endl;
}

// Test6 : Constructor used to be used as Custom Constructors with Inheritance
Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count{contract_count_param}
{
    cout << "Custom constructor for Engineer called..." << endl;
}

//BAD : Compiler error - m_address is private to person
// CivilEngineer::CivilEngineer(std::string_view fullname,int age,
//     std::string_view address,int contract_count, std::string_view speciality)
// {
//     m_full_name = fullname;
//     m_age = age;
//     //m_address = address; // Compiler Error
//     m_speciality = speciality;
//     std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
// }
// CivilEngineer::CivilEngineer(std::string_view fullname,int age,
//     std::string_view address,int contract_count, std::string_view speciality)
//     :m_full_name(fullname),m_age(age),m_address(address),m_speciality(speciality)
// {
//     std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
// }


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