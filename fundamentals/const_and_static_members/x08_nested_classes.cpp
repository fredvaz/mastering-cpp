/*

The C++20 Masterclass Section 34: Static members and Const members

General Notes:
    Inside a class definition, the keyword static declares members that are not bound to class instances.
    Static members of a class are not associated with the objects of the class: they are independent variables
    with static or thread (since C++11) storage duration or regular functions.

    !e.g., they can allow to keep track how many objects for a class are created

   [REF]:
    https://en.cppreference.com/w/cpp/language/static

*/
#include <iostream>
#include "libs/outer.hpp"

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Nested classes
            - When a Inner is private, its objects can't be created from the outside, like in main
            - Outer does not have acess to private section of Inner
            - Inner has access to private section of Outer but can only acces static members
            - Inner can directly access static members of Outer, but can't acess member variables
              without going through an object
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* We must use the scope resolution operator to go throught the namespaces to acess the Inner Class
    // Inner inner1(3, 6); //! Compiler error
    // Outer::Inner inner1(3.6); //! But now, Inner is private member of Outer Class, we not cannot acces it
    //! unless we declare the Inner Class the Public section of Outer Class

    // inner1.get_double();

    //! Outer doesn't have access to private parts of Inner, we must use the getters and setters of Inners Class
    Outer outer1(10, 20.1);
    outer1.do_something();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
