#ifndef CROW_H
#define CROW_H

//

#include "bird.hpp"

//

class Crow : public Bird
{
    
public:
    Crow() = default;
    Crow(std::string_view wing_color, std::string_view description);
    ~Crow();

    //* unique method for the Crow class (a Dog is able to cow)
    virtual void cow() const
    {
        std::cout << "Crow::cow called fro crow: " << m_description << std::endl;
    }

    //* breathe() method in animal class is override (a Crow also breathes)
    virtual void breathe() const
    {
        std::cout << "Crow::breathe called for: " << m_description << std::endl;
    }

   //* fly() method in Crow class is override (a Crow also flies)
    virtual void fly() const override
    {
        std::cout << "Crow::fly() called for bird: " << m_description << std::endl;
    }
};

#endif // CROW_H
