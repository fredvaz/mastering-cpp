/*

The C++20 Masterclass Section 30: Classes Set and Get

General Notes:
        Public methods to acess the Class member variables when these variables are private
        Since, when the member variables are declared private these are note acessible
        outside of the class or from other class

   [REF]: No
*/
#include <iostream>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Set and Get
*/

const double PI{3.1415926535897932384626433832795};

class Cylinder
{

public:
    Cylinder() = default;

    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    }

    double volume()
    {
        return PI * base_radius * height;
    }

    //* Set and Get methods to acess the private member variables in the Class
    double get_base_radius()
    {
        return base_radius;
    }

    double get_height()
    {
        return height;
    }

    void set_base_radius(double rad_param)
    {
        base_radius = rad_param;
    }

    void set_height(double height_param)
    {
        height = height_param;
    }

private:
    double base_radius{1};
    double height{1};
    
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Cylinder cylinder1(10, 10);

    std::cout << "volume: " << cylinder1.volume() << std::endl;

    // Modify the Object
    cylinder1.set_base_radius(100);
    cylinder1.set_height(10);

    std::cout << "volume : " << cylinder1.volume() << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
