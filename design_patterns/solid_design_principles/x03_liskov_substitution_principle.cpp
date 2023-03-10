/*

Design Patterns in Modern C++ Section 2: SOLID Design Principles

General Notes:

   [REF]:

*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

        * EXAMPLE: Liskov Substitution Principle
        * States that if you have let's say you have a function which takes a base class, any derived class should be
        * able to be substituted into a particular function without any problems.
*/

//* We declared this class
class Rectangle
{
protected:
    int width, height;

public:
    Rectangle(int width, int height) : width(width), height(height)
    {
    }

    int getWidth() const
    {
        return width;
    }
    int getHeight() const
    {
        return height;
    }

    //! 1. After the Square we changed these setters methods to virtual to overide them with the Square
    virtual void setWidth(int width)
    {
        Rectangle::width = width;
    }
    virtual void setHeight(int height)
    {
        Rectangle::height = height;
    }

    int area() const
    {
        return width * height;
    }
};

//* Now, we pretend to extend the Class Rectangle
class Square : public Rectangle
{
public:
    //* We declared that a Square is a Rectangle with the sides with the same size
    Square(int size) : Rectangle(size, size){};

    /*
    ! 2. Now declared these method overide for Square
    ! Unfortunately, what we've just done is we've violated the look of substitution principle, which states
    ! that if you have let's say you have a function which takes a base class (process function below)
    ! any derived class should be able to be substituted into this function without any problems.
    */
    void setWidth(int width) override
    {
        this->width = this->height = width;
    }
    void setHeight(int height) override
    {
        this->width = this->height = height;
    }
};

void process(Rectangle &r)
{
    int w = r.getWidth();
    r.setHeight(10); 
    //! This function sets the Height to 10, but when with the Square we are setting the Height equal to Width
    //! So, it will broke the expected logic here

    cout << "expected area = " << (w * 10)
         << ", got " << r.area() << "\n";
}

//* 3. One Solution could be just Make a Fcatory (see next examples)
struct RectangleFactory
{
    static Rectangle create_rectangle(int w, int h);
    static Rectangle create_square(int size);
};

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Rectangle r(3, 4);

    process(r);

    //! The problem will be that the process function will expect a area = 50 and we get a area = 100
    Square sq(5);
    process(sq);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
