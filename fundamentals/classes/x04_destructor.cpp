/*

The C++20 Masterclass: Destructor

General Notes:
        Destructors fulfill the opposite functionality of constructors: They are responsible for
        the necessary cleanup needed by a class when its lifetime ends.
        A destructor is a special member function that is called when the lifetime of an object ends.
        The purpose of the destructor is to free the resources that the object may have acquired
        during its lifetime.

   [REF]:
    https://cplusplus.com/doc/tutorial/classes2/
    https://en.cppreference.com/w/cpp/language/destructor

*/
#include <iostream>
#include <string>
#include <string_view>

//

#define EXAMPLE_
#ifdef EXAMPLE_
/*
    !Note: #define EXAMPLE_

            *EXAMPLE: Destructor
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

//* Destructor : Not possible to pass paramters to the Destructor, it will generate a Compiler error
Dog::~Dog()
{
    // This will release the memonry allocated to p_age pointer in the Constructor
    delete p_age;
    std::cout << "Dog destructor called for : " << name << std::endl;
}

void some_func()
{
    Dog my_dog("Fluffy", "Shepherd", 2);
}

void some_func(Dog dog_param) // The Destructor will be called here because we are passing a copy/by value
{
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Dog my_dog("Fluffy", "Shepherd", 2);

    // Destructor called in the Program main function end

    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    some_func(); // Destructor called in functions end

    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    Dog dog("Fluffy", "Shepherd", 2);

    some_func(dog);

    std::cout << "------------------------------ EXAMPLE_4 -------------------------------------" << std::endl;
    
    Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);
    // In this case we need to explicitly release the memory for the point in order to the Destructor
    // be called
    delete p_dog;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_ END

//
