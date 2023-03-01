#ifndef SHAPE_H
#define SHAPE_H

//

#include <string>
#include <string_view>
#include <iostream>

//

class Shape
{

public:
    Shape() = default;
    Shape(std::string_view description);
    ~Shape();

    virtual void draw() const
    {
        std::cout << "Shape::draw() method called. Drawing " << m_description << std::endl;
    }

    //* Overloading, overriding and function hiding
    virtual void draw(int color_depth) const
    {
        std::cout << "Shape::draw() overload method called with color depth: " << color_depth << std::endl;
    }

protected:
    std::string m_description{""};
};

#endif // SHAPE_H