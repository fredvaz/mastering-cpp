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
#include <memory>
#include "libs12/animal.hpp"
#include "libs12/feline.hpp"
#include "libs12/dog.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Dynamic casts
            * they are useful when we want to transform the base pointer to other pointer type
            * - Transforming from a base class pointer or reference to derived class pointer
            * or reference at run time
            * - Makes it possible to call non-polymorphic methods on derived objects
            *
            * Overusing down casts is a sign of bag design, if you find yourself doing this a lot
            * to call ploymorphic functions on derived objects, maybe you should make that function
            * polymotphic in the fisrt place
*/

void do_something_with_animal_ptr(Animal *animal);

void do_something_with_animal_ref(Animal &animal);

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Base class pointer
    Animal *animal_ptr = new Feline("stripes", "feline1");
    // animal_ptr->do_some_feline_thingy(); //! error: is a non-polymorhic function

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Dynamic cast

    // Dog *feline_ptr = dynamic_cast<Dog *>(animal_ptr);
    // feline_ptr->do_some_dog_thingy(); //! run time error: Segmentation fault
    //! We don 't have a dog information in the the above feline object Base pointer

    //* If the cast succeeds, we get a valid pointer back,
    //* if it fails, we get nullptr. So we can check before
    //* calling stuff on the returned pointer
    Feline *feline_ptr = dynamic_cast<Feline *>(animal_ptr);

    if (feline_ptr)
    {

        feline_ptr->do_some_feline_thingy(); //* OK
    }
    else
    {
        std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Can do the transformation downstream for references

    //* Base class reference
    Feline feline2("stripes", "feline2");
    Animal &animal_ref = feline2;

    //! Calling non virtual methods on animal_ref won't work
    // animal_ref.do_some_feline_thingy();

    // Dog &feline_ref{dynamic_cast<Dog &>(animal_ref)}; //! note: the { } if fails, we will not be able
    //! to call our method here
    // feline_ref.do_some_dog_thingy();

    Feline &feline_ref{dynamic_cast<Feline &>(animal_ref)}; //* note: the { } if succeeds, we will be able
    //* to call our method here
    feline_ref.do_some_feline_thingy();

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Doing proper checks with references

    Dog *feline_ptr_1{dynamic_cast<Dog *>(&animal_ref)}; //* Must be expliciti cast the Reference to Pointer

    if (feline_ptr_1)
    {
        feline_ptr_1->do_some_dog_thingy();
    }
    else
    {
        std::cout << "Couldn't cast to Dog reference,Sorry." << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    do_something_with_animal_ptr(animal_ptr);
    do_something_with_animal_ref(animal_ref);

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Note: Only do dynamic cast that are supported
    //* The output must part of the same polymorphic inheritance hierachy

    int data{45};
    // int data_ptr = &data; //! error
    // std::string data_str = dynamic_cast<std::string>(data); //! A int to a string 
                                                            //! This type of cast is not supported

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Release the dynamic memory allocated on the Heap
    delete animal_ptr;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

void do_something_with_animal_ptr(Animal *animal)
{
    std::cout << "In function taking base pointer..." << std::endl;
    Feline *feline_ptr = dynamic_cast<Feline *>(animal);

    if (feline_ptr)
    {
        feline_ptr->do_some_feline_thingy();
    }
    else
    {
        std::cout << "Couldn't cast to Feline pointer,Sorry." << std::endl;
    }
}

void do_something_with_animal_ref(Animal &animal)
{
    std::cout << "In function taking base reference..." << std::endl;
    Feline *feline_ptr_1{dynamic_cast<Feline *>(&animal)};
    if (feline_ptr_1)
    {
        feline_ptr_1->do_some_feline_thingy();
    }
    else
    {
        std::cout << "Couldn't cast to Feline reference,Sorry." << std::endl;
    }
}

#endif // EXAMPLE_1 END

//
