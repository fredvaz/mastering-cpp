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

            * EXAMPLE: sort

*/

class Book
{
    friend std::ostream &operator<<(std::ostream &out, const Book &operand);

public:
    Book(int year, std::string title)
        : m_year(year), m_title(title)
    {
    }

    bool operator<(const Book &right_operand) const
    {
        return this->m_year < right_operand.m_year;
    }

    bool operator>(const Book &right_operand) const
    {
        return this->m_year > right_operand.m_year;
    }

    bool operator==(const Book &right_operand) const
    {
        return (this->m_year == right_operand.m_year);
    }

public:
    int m_year;
    std::string m_title;
};

std::ostream &operator<<(std::ostream &out, const Book &operand)
{
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}

template <typename T>
void print_collection(const T &collection)
{

    std::cout << " Collection [";
    for (const auto &elt : collection)
    {
        std::cout << " " << elt;
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //*  Directly without predicate

    std::vector<int> collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    std::cout << "collection(unsorted): ";
    print_collection(collection);

    std::sort(std::begin(collection), std::end(collection));

    std::cout << "collection(sorted): ";
    print_collection(collection);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    // With custom compare function
    collection = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    std::cout << "collection(unsorted): ";
    print_collection(collection);

    // std::sort(std::begin(collection),std::end(collection),std::less<int>());
    // std::sort(std::begin(collection),std::end(collection),std::greater<int>());
    std::sort(std::begin(collection), std::end(collection), [](int x, int y)
              { return x < y; });

    std::cout << "collection(sorted): ";
    print_collection(collection);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Sorting collections of custom items

    std::vector<Book> books{Book(1734, "Cooking Food"),
                            Book(2000, "Building Computers"), Book(1995, "Farming for Beginners")};

    std::cout << "books(before sort): " << std::endl;
    print_collection(books);

    // std::sort(std::begin(books),std::end(books));
    // std::sort(std::begin(books),std::end(books),std::less<Book>());
    // std::sort(std::begin(books),std::end(books),std::greater<Book>());

    // Will look for > operator.
    //  Put it in and make the compiler
    // happy

    auto cmp = [](const Book &book1, const Book &book2)
    {
        return (book1.m_year < book2.m_year);
    };

    std::sort(std::begin(books), std::end(books), cmp);

    std::cout << "books(after sort): " << std::endl;
    print_collection(books);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
