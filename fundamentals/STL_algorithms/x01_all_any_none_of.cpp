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

            * EXAMPLE: All of, any_of, none_of Algorithms
            https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
*/

bool is_odd(int n)
{
    return n % 2 != 0;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // std::vector<int> collection{2, 6, 8, 49, 64, 71};
    // std::set<int> collection{2, 6, 8, 40, 64, 70};
    int collection[]{2, 6, 8, 40, 64, 70};

    //* std::all_of, using lambda function predicate/as the condition output

    if (std::all_of(std::begin(collection), std::end(collection), [](int i)
                    { return i % 2 == 0; }))
    {
        std::cout << "(std::all_of): All numbers in collection are even" << std::endl;
    }
    else
    {
        std::cout << "(std::all_of): Not all numbers in collection are even" << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* std::any_of, using functor as predicate/the condition output

    class DivisibleBy
    {
    private:
        const int d;

    public:
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; } //* Functor overrides the () constructor above
    };

    if (std::any_of(std::begin(collection), std::end(collection), DivisibleBy(7)))
    {
        std::cout << "(std::any_of): At least one number is divisible by 7" << std::endl;
    }
    else
    {
        std::cout << "(std::any_of): None of the numbers is divisible by 7" << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* std::none_of , using free standing function pointer as predicate/the condition output

    if (std::none_of(std::begin(collection), std::end(collection), is_odd))
    {
        std::cout << "(std::none_of): None of the numbers is odd" << std::endl;
    }
    else
    {
        std::cout << "(std::none_of): At least one number is odd" << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//