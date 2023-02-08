/*

The C++20 Masterclass: Section 40 : Lecture 410 : Reused Symbols in Inheritance

General Notes:


   [REF]: 
   
*/
#ifndef PARENT_H
#define PARENT_H

#include <iostream>

using namespace std;

class Parent
{
public:
    Parent() = default;
    Parent(int member_var) : m_member_var{member_var}
    {
    }
    ~Parent() = default;

    void print_var() const
    {
        cout << "The value in parent is : " << m_member_var << endl;
    }

protected:
    int m_member_var{100};
};

#endif // PARENT_H