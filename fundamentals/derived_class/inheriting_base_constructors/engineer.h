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

    // Inheriting constructors adds a level of confusion to your code, it's not clear which
    // constructor is building your object. It is recommend to avoid them and only use this 
    // feature if not other option is available

    // This will going inherit the constructors from Person class : Inheriting constructors
    using Person::Person;

public:
    //Engineer();
#ifdef Test3
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count);
#endif
    //Engineer(const Engineer& source); // Copy constructors are not inheritable
    ~Engineer();

    void build_something()
    {
        m_full_name = "John Snow";
        m_age = 23;               
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