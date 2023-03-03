#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{

protected:
    Shape() = default;
    Shape(std::string_view description);

public:
    virtual ~Shape() = default; // If destructor is not public, you won't be
                                // able to delete base_ptrs

    //* Pure virtual functions using the syntax =0
    //* - The class is going to become an abstract class, who's is not allowed any objects
    //* - Don't need declare the implementations for the methods, these will be put in by the
    //* inherting downstream classes
    virtual double perimeter() const = 0;
    virtual double surface() const = 0;

private:
    std::string m_description;
};

#endif // SHAPE_H
