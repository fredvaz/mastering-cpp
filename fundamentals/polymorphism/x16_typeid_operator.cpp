/*

The C++20 Masterclass Section 41: Polymorphism

General Notes:
    One of the key features of class inheritance is that a pointer to a derived class is type-compatible
    with a pointer to its base class. Polymorphism is the art of taking advantage of this simple but
    powerful and versatile feature.

    *Polymorphism: a base pointer or reference managing derived class objects

    *Why we need polymorphism? To scale: for example, if we have 100 shapes in our program to draw
    *we will need to implement those 100 methods.

   [REF]:
    https://en.cppreference.com/book/intro/polymorphism
    https://cplusplus.com/doc/tutorial/polymorphism/

*/
#include <iostream>
#include <memory>
#include "libs13/polymorphic.hpp"
#include "libs13/nonpolymorphic.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: typeid() operator
            * In C++ to ask a basic pointer which kind of derived object it is managed at a given moment
            * - Peak on the dynamic type of a base class pointer or reference
            * - Works only for polymorphic types
            * - Returns the dynamic type if it can and the static type otherwise
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* 1. typeid with fundemental types: returns static type

    std::cout << "typeid(int): " << typeid(int).name() << std::endl;

    if (typeid(22.2f) == typeid(float))
    {
        std::cout << "22.2f is a float" << std::endl;
    }
    else
    {
        std::cout << "22.2f is not float" << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* 2. typeid with references (polymorphic)

    std::cout << "Polymorphic references: " << std::endl;

    DynamicDerived dynamic_derived;
    DynamicBase &base_ref = dynamic_derived;

    std::cout << "Type of dynamic_derived: " << typeid(dynamic_derived).name() << std::endl;
    std::cout << "Type of base_ref: " << typeid(base_ref).name() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* 3. typeid with pointers(polymorphic)
    std::cout << "Polymorphic pointers: " << std::endl;

    DynamicBase *b_ptr = new DynamicDerived;

    std::cout << "Type of b_ptr: " << typeid(b_ptr).name() << std::endl; // static type

    //! ATTENTION :
    //!			 For pointers you have to dereference to see the dynamic type //
    std::cout << "Type of *b_ptr: " << typeid(*b_ptr).name() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* 4. type id with non polymorphic pointers and refs : We'll get static types
    //* because we're using static binding, the default behavior

    std::cout << "Non polymorphic pointers and refs: " << std::endl;

    StaticBase *b_ptr_s = new StaticDerived;
    StaticDerived staticderived;
    StaticBase &static_base_ref{staticderived};

    std::cout << "Type of *b_ptr_s: " << typeid(*b_ptr_s).name() << std::endl;
    std::cout << "Type of static_base_ref: " << typeid(static_base_ref).name() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
