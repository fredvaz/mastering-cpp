/*

The C++20 Masterclass:

General Notes:
        7) namespace-alias-definition: makes name a synonym for another namespace: see namespace alias

        Namespace aliases allow the programmer to define an alternate name for a namespace.
        They are commonly used as a convenient shortcut for long or deeply-nested namespaces.

   [REF]:
    https://en.cppreference.com/w/cpp/language/namespace_alias
    https://en.cppreference.com/w/cpp/language/namespace
*/
#include <iostream>

#define Test1

using namespace std;

namespace Level1
{
    namespace Level2
    {
        namespace Level3
        {
            const double weight{33.33};
        }
    }
}

#ifdef Test1
void test1()
{
    // Namespace aliases
    namespace data = Level1::Level2::Level3;

    //std::cout << "weight : " << Level1::Level2::Level3::weight << std::endl;
    std::cout << "weight : " << data::weight << std::endl;
    std::cout << "weight : " << data::weight << std::endl;
}
#endif