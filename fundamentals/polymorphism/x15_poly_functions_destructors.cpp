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

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Polymorphic functions and destructors
            * Don't call virtual (polymorphic) functions from constructors & destructors
            * Take carefull to the Constructor and destructor call order:
            *  - Base Constructor
            *  - Derived Constructor
            *       // Use constructed object
            *  - Derived Destructor
            *  - Base Destructor
*/

class Base
{

public:
    Base()
    {
        std::cout << "Base constructor called" << std::endl;
        // this->setup(); //! Static biding kicks in here, we will get the value set to 10 (when we expect 100)
    }
    virtual ~Base()
    {
        // this->clean_up(); //! Don't do this, because when Base destructor is called the Derived destructor
                          //! was already called during the run time
        std::cout << "Base destructor called" << std::endl;
    }
    virtual void setup()
    {
        std::cout << "Base::setup() called" << std::endl;
        m_value = 10;
    }
    virtual void clean_up()
    {
        std::cout << "Base::clean_up() called" << std::endl;
    }
    int get_value()
    {
        return m_value;
    }

protected:
    int m_value;
};

class Derived : public Base
{

public:
    Derived()
        : Base()
    {
        std::cout << "Derived constructor called" << std::endl;
    }
    virtual ~Derived()
    {
        std::cout << "Derived destructor called" << std::endl;
    }

    virtual void setup() override
    {
        std::cout << "Derived::setup() called" << std::endl;
        m_value = 100;
    }
    virtual void clean_up() override
    {
        std::cout << "Derived::clean_up() called" << std::endl;
    }
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Base *p_base = new Derived;

    //* Correct call
    p_base->setup(); //* We will set the m_value variable will the value 100 from de derived class

    auto value = p_base->get_value();             //* We get the value using a method from the Base class,
                                                  //* that doesn't exist in the Derived class, this is the beauty of poly
    std::cout << "value: " << value << std::endl; // 100

    //* Correct call
    p_base->clean_up();

    delete p_base;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
