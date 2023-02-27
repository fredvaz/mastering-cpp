/*

The C++20 Masterclass: Const Objects
                       Const Objects as function arguments
                       Const Member functions

General Notes:
        We can't modify const objects. Yet, we cam't read from them either.
        If declared a Object as const is we have to pass it to another const Object
        could potentially modify the object so the compiler will refuse to compile calls
        to them throught our const reference p parameter.

        Therefore, we shoud declara them as const member function in a class
        The correct implementation is EXAMPLE 5

   [REF]:

*/
#include <iostream>
#include "libs/dog2.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Non-const objects
*/

int main()
{

        std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

        Dog dog1("Fluffly", "Sheperd", 2);

        dog1.print_info();

        dog1.set_name("Milou");

        dog1.print_info();

        std::cout << "------------------------------------------------------------------------------" << std::endl;
        return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Const objects - Direct access
            If you flag the object as const, you want to be able to modify the object through the
            sideris. But no other function is going to work anymore because the compiler is going
            to think that you could go through those functions to modify your object.
*/

int main()
{
        std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

        const Dog dog1("Fluffly", "Sheperd", 2);

        dog1.print_info(); // Compiler error

        dog1.set_name("Milou"); // Comipler error : Dog Object is a const object we can't modify it

        std::cout << "------------------------------------------------------------------------------" << std::endl;
        return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    !Note:  #define EXAMPLE_3

            *EXAMPLE: Const objects
*/

int main()
{
        std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

        const Dog dog1("Fluffly", "Sheperd", 2);

        // Pointer to non const
        Dog *dog_ptr = &dog1; // Compiler error: invalid conversion from 'const Dog*' to 'Dog*'

        // The issue: Dog pointer is indeed a Pointer but it is a non const Pointer
        // therefore the Compiler thinks we can modify the Object

        // Non const reference
        Dog &dog_ref = dog1; // Compiler error: binding reference of type 'Dog&' to 'const Dog' discards
        // qualifiers

        // This is non-cont reference and we are trying to assign a const reference
        // to a non const reference
        // therefore the Compiler thinks we can modify the Object

        // Pointer to const
        const Dog *const_dog_ptr = &dog1; // OK : The compiler, it's going to trust this pointer now because
                                          // it is a const pointer. We can't go through this pointer to modify
                                          // the object we are pointing now.

        const_dog_ptr->set_name("Millou"); // Compiler error: passing 'const Dog' as 'this' argument discards qualifiers

        // we are trying to go through a const pointer to modify stuff
        // since it is const Object we are not allowed to modify it

        const_dog_ptr->get_name(); // Compiler error: passing 'const Dog' as 'this' argument discards qualifiers

        // It's really not modifying the object, but the compiler doesn't know
        // that doesn't know that this function
        // isn't modifying our object because what really the compiler looks
        // at is the signature of the function.

        // Const Referemce
        const Dog &const_dog_ref = dog1; // OK : is const Object to a const Reference

        const_dog_ref.set_name("Milou"); // Compiler error: passing 'const Dog' as 'this' argument discards qualifiers

        // we are going through a const Doug reference and we can't really go through
        // a constant reference to modify the object we are referencing.

        const_dog_ref.get_name(); // Compiler error: passing 'const Dog' as 'this' argument discards qualifiers

        // However, should we not expect to get the name? we are not modifying it in the function!

        std::cout << "------------------------------------------------------------------------------" << std::endl;
        return 0;
}

#endif // EXAMPLE_3 END

//

// #define EXAMPLE_4
#ifdef EXAMPLE_4
/*
    !Note:  #define EXAMPLE_4

            *EXAMPLE:  Const Objects as function arguments
*/

// Function taking parameter by value
// This causes no problem because we are working with a copy inside the function
// not directly accessing to the the const Dog object, then not modifying the original object
// Look to the memory address, they are different, tow different objects so
void function_taking_dog_by_value(Dog dog)
{
        dog.set_name("Rex");
        dog.print_info();
}

// Parameter by non-const eference
// Compiler error: binding reference of type 'Dog&' to 'const Dog' discards qualifiers
void function_taking_dog_by_non_const_ref(Dog &dog_ref)
{
        // Compiler won't allow passsing const object as argument
}

// Parameter by const reference
void function_taking_dog_by_const_ref(const Dog &dog_ref)
{
        // dog_ref.set_name("Rex"); // Compiler error: Still we can't modify it
        // dog_ref.print_info(); // Compiler error: Still the Compiler doesn't know that the
        //  function doesn't change anything in the object in the real world
}

// Parameter by non-const pointer
// Comipler error: invalid conversion from 'const Dog*' to 'Dog*'
void function_taking_dog_by_non_const_pointer(Dog *dog_ptr)
{
        // Compiler won't allow passing const Dog objects as arguments
}

// Parameter by const pointer
void function_taking_dog_by_const_pointer(const Dog *dog_ptr)
{
        // dog_ptr->set_name("Rex"); // Compiler error: Still we can't modify it
        // dog_ptr->print_info(); // Compiler error: Still the compiler that the functions does not change anything
}

int main()
{
        std::cout << "------------------------------ EXAMPLE_4 -------------------------------------" << std::endl;

        const Dog dog1("Fluffy", "Shepherd", 2);

        std::cout << "Address of the object is: " << &dog1 << std::endl;

        function_taking_dog_by_value(dog1); // OK

        // function_taking_dog_by_non_const_ref(dog1); // Compiler error

        function_taking_dog_by_const_ref(dog1); // OK

        // function_taking_dog_by_non_const_pointer(&dog1); // Compiler error

        function_taking_dog_by_const_pointer(&dog1); // OK

        std::cout << "------------------------------------------------------------------------------" << std::endl;
        return 0;
}

#endif // EXAMPLE_4 END

//

// #define EXAMPLE_5
#ifdef EXAMPLE_5
/*
    !Note:  #define EXAMPLE_5

            *EXAMPLE: Const member functions
*/

// Function taking parameter by value
void function_taking_dog_by_value(Dog dog)
{
        dog.set_name("Rex");
        dog.print_info();
}

// Parameter by const reference
void function_taking_dog_by_const_ref(const Dog &dog_ref)
{
        // dog_ref.set_name("Rex"); // Compiler error: Still we can't modify it, we didn't set as const member
        dog_ref.print_info(); // OK
}

// Parameter by const pointer
void function_taking_dog_by_const_pointer(const Dog *dog_ptr)
{
        // dog_ptr->set_name("Rex"); // Compiler error: Still we can't modify it, we didn't set as const member
        dog_ptr->print_info(); // OK
}

int main()
{
        std::cout << "------------------------------ EXAMPLE_5 -------------------------------------" << std::endl;

        const Dog dog1("Fluffy", "Shepherd", 2);

        std::cout << "Address of the object is: " << &dog1 << std::endl;

        std::cout << "print_info: ";
        dog1.print_info(); // OK

        std::cout << "by value: ";
        function_taking_dog_by_value(dog1); // OK : still is a copy passed

        std::cout << "by const ref: ";
        function_taking_dog_by_const_ref(dog1); // OK

        std::cout << "by const ptr: ";
        function_taking_dog_by_const_pointer(&dog1); // OK

        std::cout << "------------------------------------------------------------------------------" << std::endl;
        return 0;
}

#endif // EXAMPLE_5 END

//
