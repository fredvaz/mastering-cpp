#ifndef OUTER_H
#define OUTER_H

//

#include <iostream>

//* The Outer Class "inherites" the public members of Inner Class
class Outer
{

public:
    Outer(int int_param, double double_param);
    Outer();
    ~Outer();

    void do_something()
    {
        Inner inner1(10.0);
        // std::cout << "Created inner object with value : " <<inner1.get_double() <<  std::endl;
        // inner1.inner_var; //! Outer doesn't have access to private parts of Inner
        //!  Has to go through setters and getters
        inner1.do_something_with_outer(this);
        inner1.m_test; //! But has access to public members
    }

private:
    int m_var1;
    double m_var2;
    inline static int static_int{45};
public:
    double m_test2;

    //* Nested class
public:
    class Inner
    {

    public:
        Inner(double double_param);
       

        double get_double() const
        {
            //* Accessing private parts of Outer, but only the Static members
            // std::cout << "Inner accessing m_var1 : " << m_var1 << std::endl; // Compiler error.
            std::cout << "static_int : " << static_int << std::endl;
            // m_var1; //! Compiler error, not possible to acess to Outer private members
            // m_test2; //! even with the public members
            return inner_var;
        }

        //* Method to acces Outer member variables of Outer Class
        void do_something_with_outer(Outer *outer)
        {
            std::cout << "This is inner accessing private parts of outer object, m_var1: "
                      << outer->m_var1 << std::endl;
            
        }

    private:
        double inner_var;
    public:
         double m_test; //* Outer has access to Inner public members

    };
};

#endif // OUTER_H

//
