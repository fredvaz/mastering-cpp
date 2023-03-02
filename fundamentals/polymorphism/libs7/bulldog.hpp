#ifndef BULL_DOG_H
#define BULL_DOG_H

#include "dog.hpp"

class BullDog : public Dog
{

public:
    BullDog();
    virtual ~BullDog();

    //! Will throw a compiler error due to the final specifier declared in the base Dog class
// #define BULL_DOG_EX
#ifdef BULL_DOG_EX
    virtual void run() const override
    {
        std::cout << "Bulldog::run() called" << std::endl;
    }
#endif
};

#endif // BULL_DOG_H
