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
    friend ostream &operator<<(ostream &, const CivilEngineer &operand);

public:
    CivilEngineer();
    CivilEngineer(string_view fullname, int age, string_view address, 
                    int contract_count_param, string_view m_speciality_param);
    CivilEngineer(const CivilEngineer &source);
    ~CivilEngineer();

    void build_road()
    {
        get_full_name();
        m_full_name = "Daniel Gray";

        add(10, 2);

        do_something();
    }

private:
    string m_speciality{"None"};
};

#endif // CIVIL_ENGINEER_H