/*

The C++20 Masterclass: Section 40 : Lecture 410 : Reused Symbols in Inheritance

General Notes:


   [REF]:
   
*/
#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

class Child : public Parent
{
public:
    Child() = default;
    Child(int member_var) : m_member_var{member_var}
    {

    }
    ~Child() = default;

    void print_var() const
    {
        cout << "The value in child is : " << m_member_var << endl;
    }

    void show_values() const
    {
        cout << "The value in child is : " << m_member_var << endl;
        cout << "The value in parent is : " << Parent::m_member_var << endl;
        // The value in parent must be in accesible scope operator from the derived class
    }

private:
    // This variable will eclipse when we will try call in the main function
    // the parent/base class because has the same name
    int m_member_var{1000};

};
#endif // CHILD_H