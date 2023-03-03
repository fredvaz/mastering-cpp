#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

#include "stream_insertable.hpp"

class Animal : public StreamInsertable //* Abstract class as interface
{

public:
    Animal() = default;
    Animal(const std::string &description);
    ~Animal();

    virtual void breathe() const
    {
        std::cout << "Animal::breathe called for: " << m_description << std::endl;
    }

    //* Stream insertable interface. Note: the override, overrides the method in the base class
    virtual void stream_insert(std::ostream &out) const override
    {
        out << "Animal [description: " << m_description << "]";
        //* Also, we can use here the operator<< overloadind since is inherited from the base class
    }

protected:
    std::string m_description;
};

#endif // ANIMAL_H
