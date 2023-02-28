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
    https://en.cppreference.com/w/cpp/memory/weak_ptr

*/
#include <iostream>
#include <string>
#include <memory> //* Lib for the Dynamic memory management / Smart Pointers
#include "libs/dog.hpp"
#include "libs/person2.hpp" //* Weak pointer declaration here

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_

            *EXAMPLE: Weak pointers (C++11)
            * They don't own the data that they point to
            * Non owning pointeirs that don't implement the -> or* operator
            * You can't use them directly to read or modigy data
            https://en.cppreference.com/w/cpp/memory/weak_ptr
*/

int main()
{

    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Playing with basic use of weak_ptr

    std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Dog1");
    std::shared_ptr<int> shared_ptr_int_1 = std::make_shared<int>(200);

    std::weak_ptr<Dog> weak_ptr_dog_1(shared_ptr_dog_1);
    std::weak_ptr<int> weak_ptr_int_1(shared_ptr_int_1);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //! No * , or -> operators you would expect from regular pointers
    std::cout << "weak_ptr_dog_1 use count: " << weak_ptr_dog_1.use_count() << std::endl;

// #define EXAMPLE_
#ifdef EXAMPLE_
    std::cout << "Dog name : " << weak_ptr_dog_1->get_name() << std::endl;     //! Compiler error : No -> operator
    std::cout << "Pointed to value : " << *weak_ptr_int_1 << std::endl;        //! Compiler error : No * operator
    std::cout << "Pointed to address : " << weak_ptr_dog_1.get() << std::endl; //! No get method
#endif

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* To use a weak ptr you have to turn it into a shared_ptr with the lock method

    std::shared_ptr<Dog> weak_turned_shared = weak_ptr_dog_1.lock();

    std::cout << "weak_turned_shared use count: " << weak_turned_shared.use_count() << std::endl;
    std::cout << "Dog name: " << weak_turned_shared->get_name() << std::endl;
    std::cout << "Dog name: " << shared_ptr_dog_1->get_name() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_ END

//

#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Weak pointers (C++11) (Cycling dependency problem)
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Cycling dependency problem
    //* Circular dependencies
    std::shared_ptr<Person> person_a = std::make_shared<Person>("Alison");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Beth");

    //* The problem is that when the C++ runtime destroys person_a but sees that person_b is pointing
    //* to person_a. Therefore, prevent the reference count from going down all the way to zero to close
    //* person_a , the object here to be destroyed from memory
    //! Using the share_ptr the destructors are not called, and generates a memory leak
    person_a->set_friend(person_b);
    person_b->set_friend(person_a);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END
