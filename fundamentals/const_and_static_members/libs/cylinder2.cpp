
//

#include "cylinder2.hpp"

// std::string and double
const std::string Cylinder2::default_color{"Red"};
const double Cylinder2::PI{3.1415926535897932384626433832795};
const char *Cylinder2::CHAR_PTR_CONSTANT = "CString here";
const int Cylinder2::INT_ARRAY_CONSTANT[] = {10, 20, 30, 40, 50};
const float Cylinder2::FLOAT_CONSTANT = 6.98f;
const std::string Cylinder2::STRING_ARRAY_CONSTANT[] = {"String1", "String2"};

//* Using the initializer lists
Cylinder2::Cylinder2(double radius_param, double height_param)
    : WEIRD_FLOAT{33.3},
      WEIRD_C_STRING{"Weird"},
      WEIRD_INT_ARRAY_CONSTANT{10, 20, 30, 40, 50}

{
    // WEIRD_FLOAT = 33.3; //! Not allowed because it is a const

    base_radius = radius_param;
    height = height_param;
}

// Getters
double Cylinder2::get_base_radius()
{
    return base_radius;
}
double Cylinder2::get_height()
{
    return height;
}

// Setters
void Cylinder2::set_base_radius(double radius_param)
{
    base_radius = radius_param;
}
void Cylinder2::set_height(double height_param)
{
    height = height_param;
}

// Other operations on the class object
double Cylinder2::volume()
{
    return PI * base_radius * base_radius * height;
}