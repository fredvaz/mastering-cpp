/*

The C++20 Masterclass: Order of Constructor and Destructor Calls

General Notes:
    First will all the Constructors and in the Main program end it will call the Destructors
    in the reverse order, the compiler does this because the first Constructor might have other
    dependencies from the others Objects

   [REF]:
*/
#include <iostream>
#include <string_view>

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Order of Constructor and Destructor Calls
*/

class Dog
{

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog(); //* Destructor

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for : " << name << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Dog dog1("Dogyy1", "Shepherd", 2);
    Dog dog2("Dogyy2", "Shepherd", 3);
    Dog dog3("Dogyy3", "Shepherd", 5);
    Dog dog4("Dogyy4", "Shepherd", 1);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
