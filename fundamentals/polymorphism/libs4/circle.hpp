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

    //! For consequence this will hide all the other overloads we have for the general method in Oval Class
    //! This will be the only method available in the downstream classes
    virtual void draw() const override
    {
        std::cout << "Circle::draw() method called. Drawing " << m_description
                  << " with radius: " << get_x_rad() << std::endl;
    }

    //* We must create a overload here too
    //* Case where we have a overload of the method draw() in the Base Class
    // virtual void draw(int color_depth) const
    // {
    //     std::cout << "Circle::draw() overload method called with color depth: " << color_depth << std::endl;
    // }

};

#endif // CIRCLE_H