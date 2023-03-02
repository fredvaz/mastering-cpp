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
#include "libs5/animal.hpp"
#include "libs5/feline.hpp"
#include "libs5/dog.hpp"
#include "libs5/cat.hpp"
#include "libs5/bird.hpp"
#include "libs5/pigeon.hpp"
#include "libs5/crow.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Inheritance and Polymorphism at different levels
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Animal Polymorphism

    Dog dog1("drak grey", "Rex");
    Cat cat1("black strips", "Pompeu");
    Pigeon pigeon1("white", "Manel");
    Crow crow1("black", "Jota");

    //* Base Pointer Array
    Animal *animals[]{&dog1, &cat1, &pigeon1, &crow1};

    for (const auto &animal : animals)
    {
        animal->breathe();
        //* It will call the more specifc method for each animal
        //* Also, a an Animal breathes and all the animals breathes
        //* since the base pointer is type of Animal it will run OK
        // animal->run(); //! Not possible, because only the Feline types will run
        //! Therefore, we will to be more specific and pass a Base pointer of Feline type. See below
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Feline Polymorphism

    Dog dog2("dark gray", "dog2");
    Cat cat2("black stripes", "cat2");
    Pigeon pigeon2("white", "pigeon2");
    Animal animal1("some animal");

    // Feline *felines[]{&dog2, &cat2, &pigeon1}; //! Putting pigeon in felines will result in compiler error
    //!  pigeon is an Animal,a  but is not a feline.
    //* Feline pointer only allows us to store the Derived classes
    //* of Felines. If we want to to store other Animals types
    //* we must store it in a Animal pointer type instead
    Feline *felines[]{&dog2, &cat2};

    for (const auto &feline : felines)
    {
        feline->run();
    }
    //! If we want to call the breathe() method using Feline type base pointer
    //! we must set up a virtual breathe() method in the Feline Class
    //* Altough, we can access to the e.g. Cat::breathe() method if we call it directly
    //* but we are not using Polymorphism
    cat2.breathe();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Bird polymorphism

    Pigeon pigeon3("white", "pigeon1");
    Crow crow3("black", "crow1");

    Bird *birds[]{&pigeon3, &crow3};

    for (const auto &bird : birds)
    {
        bird->fly();
    }

    //* So, the conclusion is we must pay attettion to from the base Class up to the down stream classes
    //* to check how can we manipulate each type of polymorphism, for example:
    //* breathe() method exists in Animal class, also in Dog and Cat Classes, but it is not necessary to
    //* exist in Feline Class. Altough a Feline breathe too.
    //* Otherhand, Feline class contains run() method, and also in Dog and Cat Classes, but in this case
    //* does not make sense to put it in Animal Class

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
