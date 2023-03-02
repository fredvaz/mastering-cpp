#ifndef DOG_H
#define DOG_H

#include "feline.hpp"

class Dog : public Feline
{

public:
    Dog() = default;
    Dog(std::string_view fur_style, std::string_view description);
    //  ~Dog();
    virtual ~Dog(); //* Virtual destructor

    virtual void bark() const
    {
        std::cout << "Dog::bark called: Woof!" << std::endl;
    }
};

#endif // DOG_H
