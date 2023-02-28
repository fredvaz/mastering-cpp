
//

#include "circle2.hpp"

Circle::Circle(double radius, std::string_view description)
    : Oval(radius, radius, description)
{
}

Circle::~Circle()
{
}