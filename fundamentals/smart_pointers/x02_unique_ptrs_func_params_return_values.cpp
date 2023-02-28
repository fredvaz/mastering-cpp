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
    https://en.cppreference.com/w/cpp/memory/unique_ptr

*/
#include <iostream>
#include <string>
#include <memory> //* Lib for the Dynamic memory management / Smart Pointers
#include "libs/dog.hpp"
#include "libs/person.hpp"

//

#define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    !Note: #define EXAMPLE_N

            *EXAMPLE: Unique Pointers as function parametes and return values
*/

//* Passing unique ptr to functions by value
void do_something_with_dog_v1(std::unique_ptr<Dog> d)
{
    d->print_info();
}

//* Passing unique ptr to functions by reference
void do_something_with_dog_v2(const std::unique_ptr<Dog> &d)
{
    d->set_dog_name("Rior");
    d->print_info();
    // d.reset(); //! Compiler error, we are passing a const object / we can't modify it
}

//* Returning unique ptr from function by value
std::unique_ptr<Dog> get_unique_ptr()
{
    std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
    std::cout << "unique_ptr address(in) : " << &p_dog << std::endl;
    return p_dog; // The compiler does some optimizations and doesn't return a copy here
                  // it's returning something like a reference to the local object.
                  // We can prove this by looking at the address of objects in memory.
                  // This is not standard behavior, some compilers may actually return
                  // by value by making a copy. The compilers have some freedom to choose
                  // their own way to do things.
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Passing unique ptr to functions by value
    std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Max");

    //! Can't pass unique_ptr by value to a function : copies not allowed
    // do_something_with_dog_v1(p_dog_1);   // copy detected

    //* We must use the std::move
    //* Ownership will move to the body of the function and memory will be released when function returns.
    //* Not what you typically want.
    do_something_with_dog_v1(std::move(p_dog_1));

    std::cout << "p_dog_1: " << p_dog_1.get() << std::endl;
    std::cout << "Hitting back the main function" << std::endl;

    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Passing unique ptr to Class member functions by value
    std::unique_ptr<Dog> p_dog_2 = std::make_unique<Dog>("Rex");

    Person person1("John");
    // person1.adopt_dog(p_dog_1); //! Compile error as above example
    person1.adopt_dog(std::move(p_dog_2)); //* The same behavior when function is part of the class

    std::cout << "Doing something, p_dog_1 points to:  " << p_dog_2.get() << std::endl;

    //* An implicit move is done when object is created in place as a temporary
    do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));

    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    //* We can pass the std::unique_ptr parameter by reference.
    std::unique_ptr p_dog_3 = std::make_unique<Dog>("Dog2");
    p_dog_3->print_info();

    do_something_with_dog_v2(p_dog_3); //* much clean because we don't need to use the std::move
    p_dog_3->print_info();

    std::cout << "------------------------------ EXAMPLE_4 -------------------------------------" << std::endl;

    //* Returning unique ptr from function by value
    std::unique_ptr<Dog> p_dog_4 = get_unique_ptr();

    std::cout << "unique_ptr address(out) : " << &p_dog_4 << std::endl;
    p_dog_4->print_info();


    //* We can call methods inside the function returning a unique pointer
    get_unique_ptr()->print_info();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_N END

//
