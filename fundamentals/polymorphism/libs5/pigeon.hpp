#ifndef PIGEON_H
#define PIGEON_H

//

#include "bird.hpp"

//

class Pigeon : public Bird
{

public:
    Pigeon() = default;
    Pigeon(std::string_view wing_color, std::string_view description);
    ~Pigeon();

    //* unique method for the Pigeon class (a Pigeon is able to cow)
    virtual void coo() const
    {
        std::cout << "Pigeon::coo called for pigeon: " << m_description << std::endl;
    }

    //* breathe() method in animal class is override (a Pigeon also breathes)
    virtual void breathe() const
    {
        std::cout << "Pigeon::breathe called for: " << m_description << std::endl;
    }

    //* fly() method in Bird class is override (a Pigeon also flies)
    virtual void fly() const override
    {
        std::cout << "Pigeon::fly() called for bird: " << m_description << std::endl;
    }
};

#endif // PIGEON_H
