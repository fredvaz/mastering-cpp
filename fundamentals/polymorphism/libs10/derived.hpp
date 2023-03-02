#ifndef DERIVED_H
#define DERIVED_H

#include "base.hpp"

class Derived : public Base
{

public:
    Derived();
    ~Derived();
    
    //* using default parameters double a = 10 , double b = 10
    virtual double add(double a = 10 , double b = 10) const override{
        std::cout << "Derived::add() called" << std::endl;
        return (a + b + 2);
    }

};

#endif // DERIVED_H
