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

            * EXAMPLE: Iterators: begin(), end() etc.
            * Traversing containers in a unified way, regardless of the internal structure if the container.
            * Each C++ container usually also define iterators that traverse it.
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

    std::vector<int> ints1{11, 22, 33, 44};
    std::array<int, 4> ints2{100, 200, 300, 400};

    std::vector<int>::iterator it_begin = ints1.begin();
    std::vector<int>::iterator it_end = ints1.end();

    std::cout << std::boolalpha;
    std::cout << "first elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "second elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "third elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "fourth elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl;

    ++it_begin;
    std::cout << "junk elt: " << *it_begin << std::endl;
    std::cout << "it == end_it: " << (it_begin == it_end) << std::endl; // true

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << "ints1: ";
    print_collection(ints1);

    std::cout << "ints2:";
    print_collection(ints2);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
