/*

The C++20 Masterclass Section 47: STL Containers and Iterators

General Notes:
        Part of the Standard Template Library

        Iterators are a generalization of pointers that allow a C++ program to work with different data structures
        (for example, containers and ranges (since C++20)) in a uniform manner.
        The iterator library provides definitions for iterators, as well as iterator traits, adaptors, and utility
        functions.

        Since iterators are an abstraction of pointers, their semantics are a generalization of most of the semantics
        of pointers in C++. This ensures that every function template that takes iterators works as well with regular
        pointers.

        Input Iterators | Output Iterators
        Forward iterators
        Bidrectional iterators
        Random access iterators
        Contiguous iterators

   [REF]:
    https://en.cppreference.com/w/cpp/iterator
    https://cplusplus.com/reference/iterator/

*/
#include <iostream>
#include <vector>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Constant iterators
            * You cannot modify what it is pointing to
            https://en.cppreference.com/w/cpp/iterator/begin
            https://en.cppreference.com/w/cpp/iterator/end

*/

template <typename T>
void print_collection(const T &collection)
{

    auto it = collection.begin();

    std::cout << " [";
    while (it != collection.end())
    {
        std::cout << " " << *it;
        ++it;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::vector<int> numbers{11, 22, 33, 44, 55, 66, 77};

    std::cout << "numbers: ";
    print_collection(numbers);

    std::vector<int>::iterator it = numbers.begin();
    while (it != numbers.end())
    {
        *it = 100;
        ++it;
    }

    std::cout << "numbers: ";
    print_collection(numbers);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    // std::vector<int>::const_iterator c_it = numbers.cbegin();
    auto c_it = numbers.cbegin();
    while (c_it != numbers.end())
    {
        // *c_it = 100;
        ++c_it;
    }

    //*  Constant reverse iterators

    auto it1 = numbers.crbegin();
    // std::vector<int>::const_reverse_iterator it1= numbers.crbegin();

    while (it1 != numbers.crend())
    {
        //*it1 = 600; //! Compiler error, it1 is a const iterator, we can't modify
        // container data through it.
        ++it1;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
