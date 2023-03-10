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
#include <array>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Traversing container subsets with iterators
*/

template <typename T>
void print_collection(const T &collection, size_t begin_adjustment,
                      size_t end_adjustment)
{
    // Adjudt begining and end
    auto start_point = collection.begin() + begin_adjustment;
    auto end_point = collection.end() - end_adjustment;

    std::cout << " [";
    while (start_point != end_point)
    {
        std::cout << " " << *start_point;
        ++start_point;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::vector<int> ints1{11, 22, 33, 44, 55, 66, 77};
    std::array<int, 6> ints2{100, 200, 300, 400, 500, 600};

    print_collection(ints1, 1, 3);
    print_collection(ints2, 1, 1);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
