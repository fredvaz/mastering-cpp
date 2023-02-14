/*

The C++20 Masterclass: Base Class acess specifiers : Protected inheritance

General Notes:
        When a class uses protected member access specifier to derive from a base
        all public and protected members of the base class are accessible as
        protected members of the derived class (private members of the base are never
        accessible unless friended)

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#ifndef NURSE_H
#define NURSE_H

#include "person.h"

// Nurse will do protected inheritance
// Makes Public members from Base class Protected to the outside of the Derivated class

class Nurse : protected Person
{
private:
    int practice_certificate_id{0};

public:
    Nurse();
    ~Nurse();

    void treat_unwell_person()
    {
        m_full_name = "John Snow"; // OK : Inherited as Protected from Person Class where is Public member
        m_age = 23;                // OK : Inherited as Protected member from Person Class where is also Protected
        //m_address = "3000-123";  // Compiler Error : Still Private member of Person Class, will not be Inherited as Protected member
    }

    // A friend function can have a acess in the same way
    friend std::ostream &operator<<(std::ostream &out, const Nurse &operand);

};
#endif // NURSE_H