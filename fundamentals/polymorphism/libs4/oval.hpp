#ifndef OVAL_H
#define OVAL_H

//

#include "shape.hpp"
#include <string_view> //* C++17

//

class Oval : public Shape
{

public:
    Oval() = default;
    Oval(double x_radius, double y_radius, std::string_view description);
    ~Oval();

    //! This will hide all the other overloads we have for the general method in Shape Class
    //! This will be the only method available in the downstream classes
    virtual void draw() const override
    {
        std::cout << "Oval::draw() method called. Drawing " << m_description
                  << " with m_x_radius: " << m_x_radius << " and m_y_radius: " << m_y_radius
                  << std::endl;
    }

    //* We must create a overload here too
    //* Case where we have a overload of the method draw() in the Base Class
    // virtual void draw(int color_depth) const // , std::string_view color
    // {
    //     std::cout << "Oval::draw() overload method called with color depth: " << color_depth << std::endl;
    //             //   << " and color : " << color << std::endl;
    // }

    //* Case where we have a ONLY overload of the method draw() in the derived Class Oval
    //! We want to see that this method is not goinf to participate in the polymorphism Stack
    //! even if it is a virtual function. The reason: this is not going to be know by Shape pointers
    //! because it is not declared at the Shape base Class level
    virtual void draw(int color_depth, std::string_view color) const
    {
        std::cout << "Oval::draw() overload method called with color depth: " << color_depth
                  << " and color: " << color << std::endl;
    }

    double get_x_rad() const
    {
        return m_x_radius;
    }

    double get_y_rad() const
    {
        return m_y_radius;
    }

private:
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};

#endif // OVAL_H