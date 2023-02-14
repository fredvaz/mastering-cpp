/*

The C++20 Masterclass:

General Notes:

   [REF]: No
   
*/
#ifndef PERSON_H
#define PERSON_H

//#include "inheritance.h"
#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class Person
{

    friend ostream &operator<<(ostream &out, const Person &person);

public:
    Person();
    Person(string_view fullname, int age, string_view address);

#if defined(Test2) || defined(Test3) || defined(Test4)
    // Test Case : Set up our own Copy Constructor with Inheritance
    Person(const Person &source);
#endif

    ~Person();

    // Getters
    string get_full_name() const
    {
        return m_full_name;
    }

    int get_age() const
    {
        return m_age;
    }

    string get_address() const
    {
        return m_address;
    }

    int add(int a, int b) const
    {
        return a + b;
    }
    // overload function
    int add(int a, int b, int c) const
    {
        return a + b + c;
    }

    void do_something() const;

public:
    string m_full_name{"None"};

protected:
    int m_age{0};

private:
    string m_address{"None"};
};

#endif // PERSON_H