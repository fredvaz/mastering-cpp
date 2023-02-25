/*

The C++20 Masterclass: Base Class acess specifiers : Private inheritance

General Notes:
        When a class uses private member access specifier to derive from a base, all public
        and protected members of the base class are accessible as private members of the
        derived class (private members of the base are never accessible unless friended).

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"

// Engineer is doing public inheritance
class Engineer : public Person
{
    friend std::ostream &operator<<(std::ostream &out, const Engineer &operand);

public:
    Engineer();
    // EXAMPLE : Constructor used to be used as Custom Constructors with Inheritance
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count);

#if defined(Test2) || defined(Test3) || defined(Test4)
    // EXAMPLE : Set up our own Copy Constructor with Inheritance
    Engineer(const Engineer &source);
#endif

    ~Engineer();

    void build_something()
    {
        m_full_name = "John Snow"; // OK : Inherited as Private from Person Class where is Public member
        m_age = 23;                // OK : Inherited as Private member from Person Class where is also Protected
        //m_address = "897-78-723"; // Compiler Error : Still Private member of Person Class
    }

    int get_contract_count() const
    {
        return contract_count;
    }

private:
    int contract_count{0};

};

#endif // ENGINEER_H