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

    void draw() const
    {
        std::cout << "Circle::draw() called. Drawing " << m_description 
        << " with radius: " << get_x_rad() << std::endl;
    }

    //* Note: The Circle class don't need the methos to set the radius, because it will use
    //* the get_x_rad() from the Oval Class
};

#endif // CIRCLE_H