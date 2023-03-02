#ifndef WILD_CAT_H
#define WILD_CAT_H

#include "cat.hpp"

// #define WILD_CAT_EX
#ifdef WILD_CAT_EX

class WildCat : public Cat //! Can not derive from final base class

#else
class WildCat
#endif
{

public:
    WildCat();
    ~WildCat();
};

#endif // WILD_CAT_H
