/*

The C++20 Masterclass:

General Notes:

   [REF]: No
   
*/
#include "person.h"

using namespace std;

Person::Person()
{
    cout << "Default constructor for Person called..." << endl;
}

Person::Person(string &first_name_param, string &last_name_param)
    : first_name(first_name_param), last_name(last_name_param)
{
    string first_name{"John"};
    string last_name{"Snow"};
}

Person::Person(string_view fullname, int age, string_view address)
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
    cout << "Custom constructor for Person called..." << endl;
}

 // Test Case 7 : Set up our own Copy Constructor with Inheritance
Person::Person(const Person &source)
    : m_full_name{source.m_full_name}, m_age{source.m_age}, m_address{source.m_address}
{
        cout << "Copy Custom constructor for Person called..." << endl;
}

#ifndef Test3
ostream &operator<<(ostream &out, const Person &person)
{
    out << "Person [" << person.first_name << " " << person.last_name << "]";
    return out;
}
#endif

#ifdef Test3
ostream &operator<<(ostream &out, const Person &person)
{
    out << "Person [Full name : " << person.m_full_name 
        << ", Age : " << person.m_age 
        << ", Address : " << person.get_address() 
        << "]";

    return out;
}
#endif

Person::~Person()
{
}