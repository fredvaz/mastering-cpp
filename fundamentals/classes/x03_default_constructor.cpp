/*

The C++20 Masterclass: Defaulted Constructor

General Notes:
        A default constructor is a constructor which can be called with no arguments
        either defined with an empty parameter list, or with default arguments provided
        for every parameter). A type with a public default constructor is DefaultConstructible.

        class-name () = default;	(4)	(since C++11) : explicitly set up the default constructor

        Used for the case that the declared a default Constructor does do nothing
        and we have other with Parameters

   [REF]: 
    https://en.cppreference.com/w/cpp/language/default_constructor
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
    // class-name () = default;	(4)	(since C++11) : explicitly set up the default constructor
    Cylinder() = default; // If not declared it will generate a Compiler Error
                          // "no default constructor exists for class "Cylinder"C/C++(291)"

    // A Constructor that receives parameters
    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    }

    double volume()
    {
        return PI * base_radius * height;
    }
};

#ifdef Test1
/*
    Notes:
*/
void test1()
{
    // Initializes the Object with the default Constructor/Value
    // The moment you set up your own custom constructor. The compiler won't generate
    // a default non param constructor. The construction of cylinder, which is trying to use 
    // the non param constructor will fail, leading to a compiler error.
    Cylinder cylinder1;
    cout << "volume : " << cylinder1.volume() << endl;
}
#endif