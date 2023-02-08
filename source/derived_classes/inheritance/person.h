/*

The C++20 Masterclass:

General Notes:

   [REF]: No
   
*/
#ifndef PERSON_H
#define PERSON_H

#define Test3

//#include "inheritance.h"
#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class Person
{
// Private members : Derivated class cannot acess the private members of Base class Person
#ifdef Test1

private:
    string first_name{"John"};
    string last_name{"Snow"};

#endif

// Protected members : Only the Derivated class from inside can acess the protected members of Class Person
#ifdef Test2

protected:
    string first_name{"John"};
    string last_name{"Snow"};

#endif

// Base Class acess specifiers
#ifdef Test3

public:
    string m_full_name{"None"};

protected:
    int m_age{0};

private:
    string m_address{"None"};

    string first_name{"John"};
    string last_name{"Snow"};

#endif

public:
    Person(); // = default; // Used when we don't declare the Destructor implementation
    Person(string &first_name_param, string &last_name_param);
    Person(string_view fullname, int age, string_view address);
    // Test Case 7 : Set up our own Copy Constructor with Inheritance
    Person(const Person &source);
    ~Person();

    friend ostream &operator<<(ostream &out, const Person &person);

    // Getters
    string get_first_name() const
    {
        return first_name;
    }

    string get_last_name() const
    {
        return last_name;
    }

    // Setters
    void set_first_name(string_view fn)
    {
        first_name = fn;
    }

    void set_last_name(string_view fn)
    {
        last_name = fn;
    }

#ifdef Test3

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

    // Test 4
    int add(int a, int b) const
    {
        return a + b;
    }
    // overload function
    int add(int a, int b, int c) const
    {
        return a + b + c;
    }

    void do_something() const
    {
        cout << "Hello World!" << endl;
    }

#endif
};

#endif // PERSON_H