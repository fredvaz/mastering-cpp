/*

The C++20 Masterclass: Base Class acess specifiers : Private inheritance

General Notes:
        When a class uses private member access specifier to derive from a base, all public
        and protected members of the base class are accessible as private members of the
        derived class (private members of the base are never accessible unless friended).

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

class CivilEngineer : public Engineer
{
private:
    std::string m_speciality{"None"};

public:
    CivilEngineer();
    // Test6 : Constructor used to be used as Custom Constructors with Inheritance
    CivilEngineer(std::string_view fullname, int age, std::string_view address,
                  int contract_count_param, std::string_view m_speciality_param);
    ~CivilEngineer();

    void build_road()
    {
        // Compiler Error : None of the below member can be acessed
        // because are Private inherited from Person base class

        //get_full_name();
        //m_full_name = "Daniel Gray";
        //m_age = 45;

#ifdef Test4
        // Private members : Resurecting members back in context with using keyword get the
        // initial properties of the Base class Person

        get_full_name();
        m_full_name = "Daniel Gray";

        add(10, 2);

        //using Person::do_something; // Compiler Error : It is Private to Engineer class
        do_something();

#endif
    }

    // Altough is friend function it cannot access to the members of the Base class
    // because they are inherited as privated members
    friend std::ostream &operator<<(std::ostream &, const CivilEngineer &operand);
};

#endif // CIVIL_ENGINEER_H