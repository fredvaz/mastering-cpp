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

//

#define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    !Note:  #define EXAMPLE_N

            *EXAMPLE: Unique pointers and arrays
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Array allocated on the stack
    {
        std::cout << "Working with dog array on the stack" << std::endl;
        Dog dog_array[3]{Dog("Dog1"), Dog("Dog2"), Dog("Dog3")};
        for (size_t i{0}; i < 3; ++i)
        {
            dog_array[i].print_info();
        }
    }

    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Array allocated on the heap
    {
        Dog *p_dog_array_raw = new Dog[3]{Dog("Dog4"), Dog("Dog5"), Dog("Dog6")};

        for (size_t i{0}; i < 3; ++i)
        {
            p_dog_array_raw[i].print_info();
        }

        //! If we don't delete explicitly like below. Have the line commented out, the memory
        //! for the array won't be released and we won't see the destructors for Dogs 4~6 called.
        //! If we delete explicitly, everything goes as expected and the destructors are called
        //! when we exit this scope.
        delete[] p_dog_array_raw;
    }

    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    //* Array allocated on the heap with unique_ptr. Releases space for array automatically
    {
        auto arr_ptr = std::unique_ptr<Dog[]> ( new Dog[3]{Dog("Dog7"), Dog("Dog8") , Dog("Dog9")});

        //* Using the make_unique
        // auto arr_ptr = std::make_unique<Dog[]>(3); //* Works but can't initialize individual elements
                                                   //* so it will call the default constructor
        // auto arr_ptr = std::make_unique<Dog[]>(3) {Dog("Dog7"), Dog("Dog8") , Dog("Dog9")}; //! Compiler error
        // auto arr_ptr = std::make_unique<Dog[]>{Dog("Dog7"), Dog("Dog8") , Dog("Dog9")}; //! Compiler error

        for (size_t i{0}; i < 3; ++i)
        {
            arr_ptr[i].print_info();
        }
    }
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_N END

//
