#ifndef CAT_H
#define CAT_H

//

#include "feline.hpp"

//

class Cat : public Feline
{

public:
    Cat() = default;
    Cat(std::string_view fur_style, std::string_view description);
    virtual ~Cat();

    //* unique method for the Cat class (a Cat is able to miaw)
    virtual void miaw() const
    {
        std::cout << "Cat::miaw() called for cat " << m_description << std::endl;
    }

    //* breathe() method in animal class is override (a Cat also breathes)
    virtual void breathe() const
    {
        std::cout << "Cat::breathe called for: " << m_description << std::endl;
    }

    //* breathe() method in Feline class is override (a Cat also runs)
    virtual void run() const override
    {
        std::cout << "Cat " << m_description << " is running" << std::endl;
    }
};

#endif // CAT_H
