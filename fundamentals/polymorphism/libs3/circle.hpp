#ifndef CIRCLE_H
#define CIRCLE_H

//

#include "oval.hpp"

//

class Circle : public Oval
{

public:
    Circle() = default;
    Circle(double radius, std::string_view description);
    ~Circle();

    //* Using the override keyword here too just as protection
    virtual void draw() const override
    {
        std::cout << "Circle::draw() called. Drawing " << m_description 
        << " with radius: " << get_x_rad() << std::endl;
    }

};

#endif // CIRCLE_H