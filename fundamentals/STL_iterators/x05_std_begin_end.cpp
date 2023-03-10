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

            * EXAMPLE: std::begin and std::end
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int vi[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << " Collection: ";
    for (auto it = vi.begin(); it != vi.end(); ++it) //! int vi is not a object, so the begin() it will not work
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << " Collection: ";
    for (auto it = std::begin(vi); it != std::end(vi); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
