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

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Shared pointers (to fundamental types)
            std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
            Several shared_ptr objects may own the same object. The object is destroyed and its memory
            deallocated when either of the following happens:
            - the last remaining shared_ptr owning the object is destroyed;
            - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().
            https://en.cppreference.com/w/cpp/memory/shared_ptr
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* shared pointers to fundamental types

    {
        std::shared_ptr<int> int_ptr_1{new int{20}};

        std::cout << "The pointed to value is: " << *int_ptr_1 << std::endl; //* Dereference the pointer
        *int_ptr_1 = 40;                                                     //* Use the pointer to assign
        std::cout << "The pointed to value is: " << *int_ptr_1 << std::endl;

        //* returns the number of shared_ptr objects referring to the same managed object
        std::cout << "Use count: " << int_ptr_1.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Copying

        std::shared_ptr<int> int_ptr_2 = int_ptr_1; // Use count: 2

        std::cout << "The pointed to value is (through int_ptr2): " << *int_ptr_2 << std::endl;
        *int_ptr_2 = 70;
        std::cout << "The pointed to value is (through int_ptr2): " << *int_ptr_2 << std::endl;

        std::cout << "Use count for int_ptr_1: " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2: " << int_ptr_2.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Other ways to initialize shared pointers

        std::shared_ptr<int> int_ptr_3; // nullptr
        int_ptr_3 = int_ptr_1;          // Use count : 3
        std::shared_ptr<int> int_ptr_4{nullptr};
        int_ptr_4 = int_ptr_1; // Use count : 4

        std::shared_ptr<int> int_ptr_5{int_ptr_1}; // Use count : 5

        std::cout << "The pointed to value is (through int_ptr5): " << *int_ptr_5 << std::endl;
        *int_ptr_5 = 100;
        std::cout << "The pointed to value is (through int_ptr5): " << *int_ptr_5 << std::endl;

        std::cout << "Use count for int_ptr_1: " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2: " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3: " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4: " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5: " << int_ptr_5.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Use a shared pointer to manage an already existing piece of memory

        std::cout << "Use a shared pointer to manage an already existing piece of memory:" << std::endl;
        int *int_ptr_raw = new int(33);

        std::shared_ptr<int> int_ptr_6{int_ptr_raw};
        // int_ptr_raw = nullptr;
        std::cout << "The value pointed to by int_ptr_raw is (through int_ptr_6): " << *int_ptr_6 << std::endl;
        std::cout << "Use count for int_ptr_6 is: " << int_ptr_6.use_count() << std::endl;
        std::cout << "raw pointer: " << int_ptr_raw << std::endl;

        //* returns the stored pointer
        std::cout << "int_ptr_6.get(): " << int_ptr_6.get() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Reset : decrements the use count and sets the pointer to nullptr

        std::cout << "Reset..." << std::endl;
        int_ptr_5.reset(); // decrements reference count and sets int_ptr5 to nullptr
                           // after this if you show use count, for int_ptr5,you'll get 0
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3 : " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4 : " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5 : " << int_ptr_5.use_count() << std::endl;
        std::cout << "int_ptr_5.get() : " << int_ptr_5.get() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Can get the raw pointer address and use the ptr in if statements (castable to bool)

        std::cout << "Casting to bool and using in if statements..." << std::endl;
        std::cout << "int_ptr_4 : " << int_ptr_4 << std::endl;
        std::cout << "int_ptr_4.get() : " << int_ptr_4.get() << std::endl;
        std::cout << std::boolalpha;
        std::cout << "int_ptr_4->bool : " << static_cast<bool>(int_ptr_4) << std::endl;
        std::cout << "int_ptr_5->bool : " << static_cast<bool>(int_ptr_5) << std::endl;

        if (int_ptr_4)
        {
            std::cout << "int_ptr_4 pointing to something valid" << std::endl;
        }
        else
        {
            std::cout << "int_ptr_4 pointing to nullptr" << std::endl;
        }

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        std::cout << "Resetting the pointers... " << std::endl;

        //* reset() replaces the managed object
        int_ptr_4.reset();
        int_ptr_3.reset();
        int_ptr_2.reset();
        int_ptr_1.reset();
        std::cout << "Use count for int_ptr_1 : " << int_ptr_1.use_count() << std::endl;
        std::cout << "Use count for int_ptr_2 : " << int_ptr_2.use_count() << std::endl;
        std::cout << "Use count for int_ptr_3 : " << int_ptr_3.use_count() << std::endl;
        std::cout << "Use count for int_ptr_4 : " << int_ptr_4.use_count() << std::endl;
        std::cout << "Use count for int_ptr_5 : " << int_ptr_5.use_count() << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Shared pointers (with custom types / objects)
            std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
            Several shared_ptr objects may own the same object. The object is destroyed and its memory
            deallocated when either of the following happens:
            - the last remaining shared_ptr owning the object is destroyed;
            - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().
            https://en.cppreference.com/w/cpp/memory/shared_ptr
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Shared pointers with custom types / objects
    {
        std::shared_ptr<Dog> dog_ptr_1{new Dog("Dog1")};
        dog_ptr_1->print_info();

        std::cout << "Use count: " << dog_ptr_1.use_count() << std::endl;

        std::shared_ptr<Dog> dog_ptr_2 = dog_ptr_1; // Use count : 2

        std::cout << "Use count for dog_ptr_1: " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2: " << dog_ptr_2.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Initializing
        std::cout << "Initializing..." << std::endl;

        std::shared_ptr<Dog> dog_ptr_3;
        dog_ptr_3 = dog_ptr_1; // Use count : 3

        std::shared_ptr<Dog> dog_ptr_4{nullptr};
        dog_ptr_4 = dog_ptr_1; // Use count : 4

        std::shared_ptr<Dog> dog_ptr_5{dog_ptr_1}; // Use count : 5

        std::cout << "Use count for dog_ptr_1: " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2: " << dog_ptr_2.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_3: " << dog_ptr_3.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_4: " << dog_ptr_4.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_5: " << dog_ptr_5.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Can also initialize from an already existing raw pointer
        std::cout << "Initializing from already existing raw pointer" << std::endl;

        Dog *dog_ptr_raw = new Dog("Ralso");
        std::shared_ptr<Dog> dog_ptr_6{dog_ptr_raw}; //* the sharepointer will now do the memory manegement work

        dog_ptr_raw = nullptr; //* then we set to nullptr

        dog_ptr_6->print_info();

        std::cout << "Use count for dog_ptr_6 is: " << dog_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr_raw: " << dog_ptr_raw << std::endl; //* pointing to nowhere as expected

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Reset: decrements the use count and sets the pointer to nullptr

        std::cout << "Resetting" << std::endl;
        dog_ptr_5.reset(); // decrements reference count and sets int_ptr5 to nullptr
                           // after this if you show use count, for int_ptr5,you'll get 0
        std::cout << "Use count for dog_ptr_1: " << dog_ptr_1.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_2: " << dog_ptr_2.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_3: " << dog_ptr_3.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_4: " << dog_ptr_4.use_count() << std::endl;
        std::cout << "Use count for dog_ptr_5: " << dog_ptr_5.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Can get the raw pointer address and use the ptr in if statements

        std::cout << "Casting to bool and using in if statements..." << std::endl;
        std::cout << "dog_ptr_4: " << dog_ptr_4 << std::endl;
        std::cout << "dog_ptr_4.get(): " << dog_ptr_4.get() << std::endl;
        std::cout << "dog_ptr_4->bool: " << static_cast<bool>(dog_ptr_4) << std::endl;
        std::cout << "dog_ptr_5->bool: " << static_cast<bool>(dog_ptr_5) << std::endl;

        if (dog_ptr_5)
        {
            std::cout << "dog_ptr_5 pointing to something valid" << std::endl;
        }
        else
        {
            std::cout << "dog_ptr_5 pointing to nullptr" << std::endl;
        }
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

#define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    !Note:  #define EXAMPLE_3

            *EXAMPLE: Shared pointers (make_shared)
            std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.
            Several shared_ptr objects may own the same object. The object is destroyed and its memory
            deallocated when either of the following happens:
            - the last remaining shared_ptr owning the object is destroyed;
            - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset().
            https://en.cppreference.com/w/cpp/memory/shared_ptr
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    //* make_shared
    {
        std::shared_ptr<int> int_ptr_6 = std::make_shared<int>(55);
        std::cout << "The value pointed to by int_ptr_6 is: " << *int_ptr_6 << std::endl;

        std::shared_ptr<Dog> dog_ptr_6 = std::make_shared<Dog>("Salz");
        dog_ptr_6->print_info();

        std::cout << "int_ptr_6 use count: " << int_ptr_6.use_count() << std::endl; // 1
        std::cout << "dog_ptr_6 use count: " << dog_ptr_6.use_count() << std::endl; // 1

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Share the object(data) with other shared_ptr's
        std::cout << "Share the object(data) with other shared_ptr's" << std::endl;

        std::shared_ptr<int> int_ptr_7{nullptr};
        int_ptr_7 = int_ptr_6;

        std::shared_ptr<Dog> dog_ptr_7{nullptr};
        dog_ptr_7 = dog_ptr_6;

        std::cout << "int_ptr6 use count : " << int_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr6 use count : " << dog_ptr_6.use_count() << std::endl;

        std::cout << "--------------------------------------------------------------------------" << std::endl;

        //* Reset: decrements the use count

        std::cout << "Reset ptr6's" << std::endl;
        int_ptr_6.reset(); // decrement reference count, and set int_ptr6 to nullptr
                           // if reference count is zero, release the managed memory
        dog_ptr_6.reset();
        
        std::cout << "int_ptr_6 use count : " << int_ptr_6.use_count() << std::endl;
        std::cout << "dog_ptr_6 use count : " << dog_ptr_6.use_count() << std::endl;
        std::cout << "int_ptr_7 use count : " << int_ptr_7.use_count() << std::endl;
        std::cout << "dog_ptr_7 use count : " << dog_ptr_7.use_count() << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_3 END

//
