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

#define Test4
#define Test5

#include "person.h"

// Engineer is doing private inheritance
// Makes Public and protected members from Base class Private to the outside of the Derivated class

#ifndef Test5
class Engineer : private Person
#endif
#ifdef Test5

class Engineer : public Person

#endif
{
private:
    int contract_count{0};

public:
    Engineer();
    // Test6 : Constructor used to be used as Custom Constructors with Inheritance
    Engineer(std::string_view fullname, int age, std::string_view address, int contract_count_param);
    // EXAMPLE 7 : Set up our own Copy Constructor with Inheritance
    Engineer(const Engineer &source);
    ~Engineer();

    void build_something()
    {
        m_full_name = "John Snow"; // OK : Inherited as Private from Person Class where is Public member
        m_age = 23;                // OK : Inherited as Private member from Person Class where is also Protected
        //m_address = "897-78-723"; // Compiler Error : Still Private member of Person Class
    }

    // A friend function can have a acess in the same way
    friend std::ostream &operator<<(std::ostream &out, const Engineer &operand);

#ifdef Test4
    // Private members : Resurecting members back in context

    int get_contract_count() const
    {
        return contract_count;
    }

#ifndef Test5

protected:
    // Here the using keyword get the initial properties of the Base class Person
    using Person::get_address;   // OK : Public member of Base class Person
    using Person::get_age;       // OK : Public member of Base class Person
    using Person::get_full_name; // OK : Public member of Base class Person
    using Person::m_full_name;   // OK : Public member of Base class Person
    //using Person::m_address;   // Compiler Error : Still a Private member of Base class Person

public:
    using Person::add; // It will give access to the two overload functions
    using Person::do_something;

#endif
#endif
};

#endif // ENGINEER_H