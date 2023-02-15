/*

The C++20 Masterclass: Nested namespaces

General Notes:
        nested namespace definition: namespace A::B::C { ... } is equivalent to
        namespace A { namespace B { namespace C { ... } } }.

   [REF]:
    https://en.cppreference.com/w/cpp/language/namespace
*/
#include <iostream>

#define Test1

namespace Hello
{
    unsigned int age{23};

    namespace World
    {
        int local_var{44};

        void say_something()
        {
            std::cout << "Hello there " << std::endl;
            std::cout << "The age is : " << age << std::endl;
        }
    }

    void do_something()
    {
        // Here we don't have direct access to local_var, we have to go
        // through the namespace.
        std::cout << "Using local_var : " << World::local_var << std::endl;
    }
}

#ifdef Test1
void test1()
{
    // To access the say_something that is inside a nested namespace/one namespace inside other
    Hello::World::say_something();
    
    Hello::do_something();
}
#endif