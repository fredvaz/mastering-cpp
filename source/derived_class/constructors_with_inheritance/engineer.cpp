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

Engineer::Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count{contract_count_param}
{
    cout << "Custom constructor for Engineer called..." << endl;
}

#if defined(Test2)
// Test Case : whitout initialize the Person object class in the Constructor
Engineer::Engineer(const Engineer &source)
    : contract_count{source.contract_count}
{
    cout << "Copy Custom constructor for Engineer called..." << endl;
}
#elif defined(Test3) || defined(Test4)
// Test Case : Set up our own Copy Constructor with Inheritance from Person class : Person(source)

// GOOD desgin : pass the Enginneer object directly : Person(source)
Engineer::Engineer(const Engineer &source)
    : Person(source), contract_count{source.contract_count}
{
    cout << "Copy Custom constructor for Engineer called..." << endl;
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

// Test Case : Set up our own Copy Constructor with Inheritance
// The catch is in Engineer class, where we have to initialize the Person class
// The below example: it will call ther Person default Constructor because we are not initialize the Person Class

// BAD example:
// Engineer::Engineer(const Engineer &source)
//     : contract_count{source.contract_count}
// {
//     cout << "Copy Custom constructor for Engineer called..." << endl;
// }
// Another BAD example: m_address is a private member and this will create a tempory copy for the Person classs
// Engineer::Engineer(const Engineer &source)
//     : Person(source.m_full_name, source.m_age, source.m_address), contract_count{source.contract_count}
// {
//     cout << "Copy Custom constructor for Engineer called..." << endl;
// }

// Another example: this will work because we are returning the address using a public method
// but we still are setting up a temporary person copy, which we are copying from to then forward the data
// This is a BAD design
// Engineer::Engineer(const Engineer &source)
//     : Person(source.m_full_name, source.m_age, source.get_address()), contract_count{source.contract_count}
// {
//     cout << "Copy Custom constructor for Engineer called..." << endl;
// }
#endif

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