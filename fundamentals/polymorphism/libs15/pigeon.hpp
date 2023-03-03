#ifndef PIGEON_H
#define PIGEON_H

#include "bird.hpp"

class Pigeon : public Bird
{

public:
    Pigeon() = default;
    Pigeon(const std::string &wing_color, const std::string &description);
    ~Pigeon();

    virtual void coo() const
    {
        std::cout << "Pigeon::coo called for pigeon: " << m_description << std::endl;
    }

    //* Stream insertable interface. Note: the override, overrides the method in the base class
    virtual void stream_insert(std::ostream &out) const override
    {
        out << "Pigeon [description: " << m_description << ", wing_color: " << m_wing_color << "]";
    }
};

#endif // PIGEON_H
