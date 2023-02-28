/*

The C++20 Masterclass Section 37: Smart Pointers

General Notes:
    *Raw Pointers:
    - new: creates and initializes objects with dynamic storage duration, that is, objects whose lifetime
    is not necessarily limited by the scope in which they were created.
    - delete: Destroys object(s) previously allocated by the new expression and releases obtained memory
    area.

    *Smart Pointers allows us avoid the use of the delete keyword, and they managge the memory for us

   [REF]:
    https://en.cppreference.com/w/cpp/language/new
    https://en.cppreference.com/w/cpp/language/delete
    https://en.cppreference.com/w/cpp/memory/shared_ptr

*/
#include <iostream>
#include <string>
#include <memory> //* Lib for the Dynamic memory management / Smart Pointers
#include "libs/dog.hpp"

//

#define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    !Note: #define EXAMPLE_N

            *EXAMPLE: Shared pointers as functions parameters and return values
            !Note: Returning by reference not recommended
*/

//* Passing by value
void use_dog_v1(std::shared_ptr<Dog> dog)
{
    std::cout << "shared_ptr passed by value, dog_name: " << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v1 function: " << dog.use_count() << std::endl; //! 2
}

//* Passing by non const reference
void use_dog_v2(std::shared_ptr<Dog> &dog)
{
    //! Since no copy is made, we won't see the reference count increment here
    dog->set_dog_name("Riol");
    // dog.reset(new Dog()); // Passed by non const ref
    std::cout << "shared_ptr passed by non const reference (dog name changed in function), dog_name: "
              << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v2 function: " << dog.use_count() << std::endl;
}

//* Passing by const reference
void use_dog_v3(const std::shared_ptr<Dog> &dog)
{
    //! Since no copy is made, we won't see the reference count increment here
    dog->set_dog_name("Simy"); //! We can change the dog object even though
                               //! shared_ptr is passed by ref. The const protects the shared_ptr
                               //! object itself, not the pointed to object.
    // dog.reset(new Dog()); // Passed by const ref Not possible
    std::cout << "shared_ptr passed by const reference (dog name changed in function), dog_name: " << dog->get_name() << std::endl;
    std::cout << "use count in use_dog_v3 function: " << dog.use_count() << std::endl;
}

//* Returning by value
//*     Returning a shared_ptr by value goes through return value optimization and at the
//*     end no copy is made, we have a single shared ptr with a reference count of 1,
//*     just like when we create a shared directly with make_shared.
std::shared_ptr<Dog> get_shared_ptr_v1()
{
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v1");
    std::cout << "Managed dog address(in): " << dog_ptr.get() << std::endl;
    return dog_ptr;
}

//! RETURNING SHARED_PTR BY REF( CONST OR NON CONST) IS A RECIPE FOR DISASTER. DON'T DO IT
//! Compiler warning: reference to local variable ‘dog_ptr’ returned
//! returning std::shared_ptr by reference doesn't properly increment the reference count,
//!  which opens up the risk of deleting something at the wrong time. We'll get a crash
std::shared_ptr<Dog> &get_shared_ptr_v2()
{
    std::shared_ptr<Dog> dog_ptr = std::make_shared<Dog>("Internal Dog_v2");
    return dog_ptr;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Passing by value : A copy will be made, increment the ref count in function body

    std::cout << "Passing shared_ptr by value: " << std::endl;

    std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Filld");
    std::cout << "shared_ptr_dog_1 use count (before): "
              << shared_ptr_dog_1.use_count() << std::endl; //! 1
    //* When the function terminates the use_count() is reset to 1
    //* the shared_pointer is no more in use inside de function
    use_dog_v1(shared_ptr_dog_1);

    std::cout << "shared_ptr_dog_1 use count (after): "
              << shared_ptr_dog_1.use_count() << std::endl; //! 1

    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Passing by non const reference
    //*     No copy is made, reference count doesn't increment in function body

    std::cout << "Passing by non const reference: " << std::endl;
    std::shared_ptr<Dog> shared_ptr_dog_2 = std::make_shared<Dog>("Flizy");

    std::cout << "shared_ptr_dog_2 use count (before): "
              << shared_ptr_dog_2.use_count() << std::endl;

    use_dog_v2(shared_ptr_dog_2);

    std::cout << "shared_ptr_dog_2 use count (after): "
              << shared_ptr_dog_2.use_count() << std::endl;

    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    //* Passing by const reference
    //*     The const just protects the shared pointer object itself, it doesn't
    //*     protect the pointed to value from changes.

    std::cout << "Passing by const reference: " << std::endl;

    std::shared_ptr<Dog> shared_ptr_dog_3 = std::make_shared<Dog>("Kitzo");

    std::cout << "shared_ptr_dog_3 use count(before): "
              << shared_ptr_dog_3.use_count() << std::endl; // 1

    use_dog_v3(shared_ptr_dog_3);

    std::cout << "shared_ptr_dog_3 use count(after): "
              << shared_ptr_dog_3.use_count() << std::endl; // 1

    std::cout << "------------------------------ EXAMPLE_4 -------------------------------------" << std::endl;

    //* Returning by value
    //*     Returning a shared_ptr by value goes through return value optimization and at the
    //*     end no copy is made, we have a single shared ptr with a reference count of 1, just
    //*     like when we create a shared directly with make_shared.

    std::shared_ptr<Dog> shared_ptr_dog_4 = get_shared_ptr_v1();

    std::cout << "Managed dog address (out): " << shared_ptr_dog_4.get() << std::endl;
    std::cout << "shared_ptr_dog_4 use count: " << shared_ptr_dog_4.use_count() << std::endl;

    std::cout << "------------------------------ EXAMPLE_5 -------------------------------------" << std::endl;

    //! Returning by reference : not recommended.
    std::shared_ptr<Dog> &shared_ptr_dog_5 = get_shared_ptr_v2();

    std::cout << "ref count: " << shared_ptr_dog_5.use_count() << std::endl;

    //! Segmentation fault

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_N END

//
