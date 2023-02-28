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

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Shared pointers with arrays C++17
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* C++17 only: Recommended
    std::shared_ptr<int[]> shared_ptr_int_arr_1(new int[10]{1, 2, 3, 4, 5, 6, 7, 8});
    std::shared_ptr<Dog[]> shared_ptr_dog_arr_1(new Dog[10]{Dog("Dog1"), Dog("Dog2")});

    //* Setting elements
    shared_ptr_int_arr_1[3] = 28;
    shared_ptr_dog_arr_1[1] = Dog("Fluzzy");

    //* Read int array
    std::cout << std::endl;
    std::cout << "Reading data from arrays" << std::endl;
    std::cout << "Reading shared_ptr_int_arr_1: " << std::endl;
    for (size_t i{0}; i < 10; ++i)
    {
        std::cout << "shared_ptr_int_arr_1[" << i << "] : " << shared_ptr_int_arr_1[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Reading shared_ptr_dog_arr_1: " << std::endl;
    for (size_t i{0}; i < 10; ++i)
    {
        std::cout << "shared_ptr_dog_arr_1[" << i << "] : " << shared_ptr_dog_arr_1[i].get_name() << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
