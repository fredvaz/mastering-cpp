#ifndef DOG_H
#define DOG_H

//

#include "feline.hpp"

//

class Dog : public Feline
{

public:
    Dog() = default;
    Dog(std::string_view fur_style, std::string_view description);
    virtual ~Dog();

    //* unique method for the Dog class (a Dog is able to bark)
    virtual void bark() const
    {
        std::cout << "Dog::bark called: Woof!" << std::endl;
    }

    //* breathe() method in animal class is override (a Dog also breathes)
    virtual void breathe() const override
    {
        std::cout << "Dog::breathe called for: " << m_description << std::endl;
    }

    //* breathe() method in Feline class is override (a Dog also runs)
    virtual void run() const override
    {
        std::cout << "Dog " << m_description << " is running" << std::endl;
    }
};

#endif // DOG_H
