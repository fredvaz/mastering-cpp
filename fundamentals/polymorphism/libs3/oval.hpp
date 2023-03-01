#ifndef OVAL_H
#define OVAL_H

//

#include "shape.hpp"

//

class Oval : public Shape
{

public:
    Oval() = default;
    Oval(double x_radius, double y_radius,
         std::string_view description);
    ~Oval();

    //! draW() with W upper case as a typo error for example, the Compiler will not find any error
    //! Compiler error: ‘virtual void Oval::draW() const’ marked ‘override’, but does not override
    //* Recommend to use the override together when declared as virtual function
    // virtual void draW() const
    // virtual void draW() const override
    virtual void draw() const override //* Method correct after the Compiler error
    {
        std::cout << "Oval::draw() called. Drawing " << m_description
                  << " with m_x_radius: " << m_x_radius << " and m_y_radius: " << m_y_radius
                  << std::endl;
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