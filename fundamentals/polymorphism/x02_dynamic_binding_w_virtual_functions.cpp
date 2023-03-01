/*

The C++20 Masterclass Section 41: Polymorphism

General Notes:
    One of the key features of class inheritance is that a pointer to a derived class is type-compatible
    with a pointer to its base class. Polymorphism is the art of taking advantage of this simple but
    powerful and versatile feature.

    *Polymorphism: a base pointer or reference managing derived class objects

    *Why we need polymorphism? To scale: for example, if we have 100 shapes in our program to draw
    *we will need to implement those 100 methods.

   [REF]:
    https://en.cppreference.com/book/intro/polymorphism
    https://cplusplus.com/doc/tutorial/polymorphism/

*/
#include <iostream>
#include "libs2/shape.hpp"
#include "libs2/oval.hpp"
#include "libs2/circle.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Dynamic binding (Polymorphism) with virtual functions
            *Now, the Compiler will look to the Type of each Object we arew bifing and not the base pointer
*/

//* The real use of Polymorphism:
//* The first thing we can achieve is set up one single method, which is really going to dra any kind
//* of shape we throw at it
void draw_shape(Shape *s)
{
    s->draw();
}

void draw_shape_v1(const Shape &s_r)
{
    s_r.draw();
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Shape shape1("Shape1");
    Oval oval1(2.0, 3.5, "Oval1");
    Circle circle1(3.3, "Circle1");

    //* Call method by default for each Object
    shape1.draw();
    oval1.draw();
    circle1.draw();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Base pointers plus Dynamic binding (Polymorphism) with virtual functions

    Shape *shape_ptr = &shape1;
    shape_ptr->draw(); //* Calls the Shape method draw()

    shape_ptr = &oval1; //* Pointing to oval1 object

    shape_ptr->draw(); //* OK: Calls the the Oval method draw()

    shape_ptr = &circle1;
    shape_ptr->draw(); //* OK: Calls the the Circle method draw()

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Base references:
    Shape &shape_ref = oval1;
    shape_ref.draw(); //* Calls Shape::draw()

    Shape &shape_ref2 = oval1;
    shape_ref2.draw(); //* Calls Oval::draw()

    Shape &shape_ref3 = circle1;
    shape_ref3.draw(); //* Calls Circle::draw()

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* The real use of Polymorphism:
    //* The first thing we can achieve is set up one single method, which is really going to dra any kind
    //* of shape we throw at it
    draw_shape(&shape1);
    draw_shape(&oval1); // note: weneed the & to pass the address is delcared as pointer in the function
    draw_shape(&circle1);

    draw_shape_v1(shape1); // note: we don't need the &, is delcared as reference in the function
    draw_shape_v1(oval1);
    draw_shape_v1(circle1);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Using Raw pointers (shape_ptr)
    shape_ptr = &oval1;
    shape_ptr->draw(); //* virtual method
    // shape_ptr->get_x_rad(); //! we cannot call non virtual method

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Shapes stored in collections
    Shape *shape_collection[]{&shape1, &oval1, &circle1}; //* Shape is Pointer

    for (Shape *s_ptr : shape_collection) //* range for C++
    {
        s_ptr->draw();
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
