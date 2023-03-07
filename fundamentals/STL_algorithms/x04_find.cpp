/*

The C++20 Masterclass Section 49: STL Algorithms

General Notes:
        Part of the Standard Template Library

        The algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting
        manipulating) that operate on ranges of elements.

        Note: In C++20 there is a huge update to the STL Algorithms

   [REF]:
    https://en.cppreference.com/w/cpp/algorithm

*/
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: find
            https://en.cppreference.com/w/cpp/algorithm/find
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // int n = 23;
    int n = 24;

    std::vector<int> collection{14, 24, 72, 8, 98, 112};

    auto result = std::find(std::begin(collection), std::end(collection), n);

    if (result != std::end(collection))
    {
        std::cout << "collection contains: " << n << std::endl;
    }
    else
    {
        std::cout << "collection does not contain: " << n << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    auto odd = [](int x)
    {
        if ((x % 2) != 0)
            return true;
        return false;
    };

    auto odd_n_position = std::find_if(std::begin(collection), std::end(collection), odd);

    if (odd_n_position != std::end(collection))
    {
        std::cout << "collection contains at least one odd number: " << *odd_n_position << std::endl;
    }
    else
    {
        std::cout << "collection does not contain any odd number" << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
