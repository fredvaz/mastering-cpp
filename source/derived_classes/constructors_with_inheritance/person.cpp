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

Person::Person(string_view fullname, int age, string_view address)
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
    cout << "Custom constructor for Person called..." << endl;
}

#if defined(Test2) || defined(Test3) || defined(Test4)
// Test Case : Set up our own Copy Constructor with Inheritance
Person::Person(const Person &source)
    : m_full_name{source.m_full_name}, m_age{source.m_age}, m_address{source.m_address}
{
        cout << "Copy Custom constructor for Person called..." << endl;
}
#endif

void Person::do_something() const{
    cout << "Hello World!" << endl;
}

ostream &operator<<(ostream &out, const Person &person)
{
    out << "Person [Full name : " << person.m_full_name 
        << ", Age : " << person.m_age 
        << ", Address : " << person.get_address() 
        << "]";

    return out;
}

Person::~Person()
{
}