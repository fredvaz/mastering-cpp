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

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: for each Algorithm
            https://en.cppreference.com/w/cpp/algorithm/for_each

*/

struct Sum
{
    void operator()(int n) { sum += n; } //* note: operator() = Functor
    int sum{0};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::vector<int> nums{3, 4, 2, 8, 15, 267};
    // int nums[]{3, 4, 2, 8, 15, 267};
    // std::set<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int &n)
    {
        std::cout << " " << n;
    };

    //* Print each elt in the collection: lambda function predicate
    std::for_each(std::begin(nums), std::end(nums), print);

    std::cout << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Predicate that modifies elements in place

    std::for_each(std::begin(nums), std::end(nums), [](int &n)
                  { n++; });

    //* Print
    std::for_each(std::begin(nums), std::end(nums), print);
    std::cout << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Capturing result through stateful functor that's returned
    //* calls Sum::operator() for each number

    Sum s;
    s = std::for_each(std::begin(nums), std::end(nums), s);
    std::cout << "result: " << s.sum << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Using a lambda that captures a local variables by ref and modifies it.
    int our_result{0};
    
    std::for_each(std::begin(nums), std::end(nums), [&our_result](int n)
                  { our_result += n; });

    std::cout << "result: " << our_result << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
