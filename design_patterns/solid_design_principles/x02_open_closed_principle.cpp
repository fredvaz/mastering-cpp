/*

Design Patterns in Modern C++ Section 2: SOLID Design Principles

General Notes:

   [REF]:

*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

        * EXAMPLE: Open-Closed Principle (OCP)
        * open for extension, closed for modification
        * The open closed principle basically states that your systems should be open to extensions.
        * So you should be able to extend systems by inheritance, for example, but closed for modification.
*/

enum class Color
{
    red,
    green,
    blue
};

enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    //* Supose we are asked to have a Method to filter by Color
    vector<Product *> by_color(vector<Product *> items, Color color)
    {
        vector<Product *> result;
        for (auto &i : items)
            if (i->color == color)
                result.push_back(i);
        return result;
    }

    //* Now we are asked to have a Method to filter by Size
    vector<Product *> by_size(vector<Product *> items, Size size)
    {
        vector<Product *> result;
        for (auto &i : items)
            if (i->size == size)
                result.push_back(i);
        return result;
    }

    //* Now we are asked again to a method to fitler by Size and Color
    vector<Product *> by_color_and_size(vector<Product *> items, Size size, Color color)
    {
        vector<Product *> result;
        for (auto &i : items)
            if ((i->size == size) && (i->color == color))
                result.push_back(i);
        return result;
    }
    //! So this it's a problematic approach to this problem because we have two criteria
    //! and we already have three functions that we have three criteria and we would have eight functions.
    //* The open closed principle basically states that your systems should be open to extensions.
    //* So you should be able to extend systems by inheritance, for example, but closed for modification.
    //! And unfortunately, what we're doing here is we're modifying existing code instead of inheriting
    //! and thereby extending the system.
};

//* Solution:
//* we can build a better filter and we're going to do it using the specification pattern,
//* which is an enterprise pattern, a pattern related to data and.
//* Working with data, so the way we're going to do this is by defining to interfaces, we're going to
//* define interfaces called specification and filter.

template <typename T>
struct AndSpecification;

//* We define a BASE Specification Interface
template <typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0; //* pure virtual function

    //* bonus: to make green_and_large more compact
    //! new: breaks OCP if you add it post-hoc
    // AndSpecification<T> operator&&(Specification<T> &&other)
    // {
    //     return AndSpecification<T>(*this, other);
    // }
};

//* new:
template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{
    return {first, second};
}

//* We define a BASE Filter Interface
template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

//* start using them to build filters off product.
struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (auto &item : items)
            if (spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

//* Now, what we have to do is we have to specify the different specifications that
//* we want to be able to use to actually search: by size, color or size and color
struct ColorSpecification : Specification<Product>
{
    Color color;

    ColorSpecification(Color color) : color(color) {}

    bool is_satisfied(Product *item) const override
    {
        return item->color == color;
    }
};

//* And now we other Specifications? we do the following
struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size size) : size{size} {}

    bool is_satisfied(Product *item) const override
    {
        return item->size == size;
    }
};

template <typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T> &first;
    const Specification<T> &second;

    AndSpecification(const Specification<T> &first, const Specification<T> &second)
        : first(first), second(second) {}

    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    vector<Product *> items{&apple, &tree, &house}; //! Look better how vector works: STL containers Section 47

    //* Bad Design

    ProductFilter pf;
    auto green_things = pf.by_color(items, Color::green);

    for (auto &item : green_things)
        cout << item->name << " is green\n";

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Good Design

    BetterFilter bf;
    ColorSpecification green(Color::green);

    for (auto &item : bf.filter(items, green))
        cout << item->name << " is green\n";

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);

    //* bonus: to make green_and_large more compact. Refer to the Specification Class above
    // auto spec = ColorSpecification(Color::green) && SizeSpecification(Size::large);
    auto spec = green && large;

    for (auto &item : bf.filter(items, spec)) // bf.filter(items, green_and_large)
        cout << item->name << " is green and large\n";

    // warning: the following will compile but will NOT work
    // auto spec2 = SizeSpecification{Size::large} &&
    //              ColorSpecification{Color::blue};

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
