/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <string>

//

// #define EXAMPLE_1
#if defined(EXAMPLE_1) || defined(EXAMPLE_2) || EXAMPLE_3

class Car; // Forward declaration

class Point
{
    // Stream insertion operation operator as free function NON memmber function of the Class
    friend std::ostream &operator<<(std::ostream &os, const Point &p);

public:
    Point() = default;
    Point(double x, double y)
        : m_x(x), m_y(y)
    {
    }
    //* Study Case for the Copy Assignment Operator
    Point(double x, double y, int data)
        : m_x(x), m_y(y), p_data(new int(data))
    {
    }
    //* Copy Constructor
    Point(const Point &p);

    ~Point() = default;

    //* Solution: Custom Copy Assignment Operator
    Point &operator=(const Point &right_operand)
    {
        std::cout << "Custom Copy Assignment operator called" << std::endl;
        if (this != &right_operand) //! Check if the current object is not the same as the object we are trying to copy from
        {
            delete p_data;
            p_data = new int(*(right_operand.p_data));
            m_x = right_operand.m_x;
            m_y - right_operand.m_y;
        }
        return *this; // return the data //! Reminder "this" keyword is a the current/self class object address
    }

    //* Copy Assignment for Other Types
    void operator=(const Car &c);

    void set_data(int data)
    {
        *p_data = data;
    }

private:
    double m_x{};
    double m_y{};
    //* Study Case for the Copy Assignment Operator
    int *p_data;
};

// Stream insertion operation operator as free function NON memmber function of the Class
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << " data: " << *(p.p_data) << " ]";
    return os;
}

//* Copy Constructor
Point::Point(const Point &p)
{
    std::cout << "Copy Constructor called to copy " << p << std::endl;
    if (this != &p) //! Check if the current object is not the same as the object we are trying to copy from
    {
        delete p_data;
        p_data = new int(*(p.p_data));
        m_x = p.m_x;
        m_y - p.m_y;
    }
}

#endif // IF_END

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Copy Assignment Operator
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    // Point p1(6, 6);
    // Point p2(4, 4);
    Point p1(4, 4, 3);
    Point p2(8, 8, 6);
    Point p77(3, 3, 3);

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //* Copy Assignment Operator
    //! If no Copy Assigment Operator declared the Compiler will use a Generated Copy Assigment operator
    //! if we have only have non pointer or member variables in our class
    p2 = p1;

    // Chain Assigmnets Another example, in this case p1 and p2 data is changed to the p77 data
    // this possible because we are returnig by reference in our copy assigment operator
    p1 = p2 = p77;
    // p1.operator=(p2.operator=(p77)); // What the Compiler does under the hood

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //* Data change
    p1.set_data(8);
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl; //! Also changes to 15, the compiler copy assigment it will do a shadow copy
    //! It's going to be blindy copyiong the addresses we have in our member variable of the Class

    //* Solution: Custom Copy Assignment Operator

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Copy Constructor
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Copy Constructor
    // Point p3(p3); //! Segmentation fault
    Point p3(7, 7, 7);
    // Point p4(p3); // Default case
    Point p4 = p3; //! Copy assigment operator, in this case it call the Copy Constructor

    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;
    std::cout << "--------------------------------" << std::endl;

    p3.set_data(9);

    std::cout << "p3: " << p3 << std::endl;
    std::cout << "p4: " << p4 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    !Note:  #define EXAMPLE_3

            *EXAMPLE: Copy Assignment for Other Types
*/

class Car
{
    friend std::ostream &operator<<(std::ostream &os, const Car &c);

public:
    Car() = default;
    Car(const std::string &color, int speed);
    ~Car();

    double get_speed() const
    {
        return m_speed;
    }
    std::string get_color() const
    {
        return m_color;
    }

private:
    std::string m_color;
    double m_speed;
};

//* Copy Assignment for Other Types
void Point::operator=(const Car &c)
{
    m_x = m_y = c.get_speed(); // Just an example, not functional, this does make sense in the real world
    *p_data = c.get_speed();
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    Point p1(3, 3, 3);
    Car c1("red", 60);

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "--------------------------------" << std::endl;

    //* Copy Assignment for Other Types
    p1 = c1;

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "c1: " << c1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Car::Car(const std::string &color, int speed) : m_color(color), m_speed(speed)
{
}

Car::~Car()
{
}

// Stream insertion operation operator as free function NON memmber function of the Class
std::ostream &operator<<(std::ostream &os, const Car &c)
{
    os << "Point [ color: " << c.m_color << ", speed: " << c.m_speed << " ]";
    return os;
}

#endif // EXAMPLE_3 END

//
