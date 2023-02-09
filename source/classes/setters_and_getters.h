/*

The C++20 Masterclass: Set and Get

General Notes:
        Public methods to acess the Class member variables when these variables are private
        Since, when the member variables are declared private these are note acessible
        outside of the class or from other class

   [REF]: No
*/

#define Test1

using namespace std;

const double PI{3.1415926535897932384626433832795};

class Cylinder
{

private:
    double base_radius{1};
    double height{1};

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

    // Set and Get methods to acess the private member variables in the Class
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
};

#ifdef Test1

void test1()
{
    Cylinder cylinder1(10, 10);

    cout << "volume : " << cylinder1.volume() << endl;

    // Modify the Object
    cylinder1.set_base_radius(100);
    cylinder1.set_height(10);

    cout << "volume : " << cylinder1.volume() << endl;
}
#endif

#ifdef Test2
/*
    Notes:
*/
void test2()
{
}
#endif