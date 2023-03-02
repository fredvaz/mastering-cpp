
//

#include "ellipse.hpp"

//

//* Static member: for the seconnd part of the Example
int Ellipse::m_count{0};

Ellipse::Ellipse(double x_radius, double y_radius,
                 std::string_view description)
    : Shape(description), m_x_radius(x_radius),
      m_y_radius(y_radius)
{
    //* Static member: for the seconnd part of the Example
    ++m_count;
}

Ellipse::Ellipse()
    : Ellipse(0.0, 0.0, "NoDescription")
{
}

Ellipse::~Ellipse()
{
    //* Static member: for the seconnd part of the Example
    --m_count;
}
