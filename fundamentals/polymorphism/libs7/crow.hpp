#ifndef CROW_H
#define CROW_H

#include "bird.hpp"

class Crow : public Bird
{

public:
    Crow() = default;
    Crow(std::string_view wing_color, std::string_view description);
    virtual ~Crow();

    virtual void cow() const
    {
        std::cout << "Crow::cow called fro crow: " << m_description << std::endl;
    }

    //! This will give a compiler error is fly is marked as final in Bird
// #define CROW_H_EX
#ifdef CROW_H_EX
    virtual void fly() const override
    {
    }
#endif

};

#endif // CROW_H
