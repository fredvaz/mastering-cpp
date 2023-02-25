/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.
        Functors
        Objects of a class that overloads the () operator

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <string>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Functors
*/

class Print
{
public:
    void operator()(const std::string &name) const
    {
        std::cout << "The name is : " << name << std::endl;
    }

    std::string operator()(const std::string &last_name,
                           const std::string &first_name) const
    {
        return (last_name + " " + first_name);
    }
};

void do_something(const Print &printer)
{
    printer("Snow");
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Print print;
    print("John");
    do_something(print);
    std::cout << print("Daniel", "Gray") << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
