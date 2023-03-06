/*

The C++20 Masterclass Section 43: BoxContainer clas: Practing what we know

General Notes:
        Exercise example: A Box that can contains things (int, doubles etc)

   [REF]: No

*/
#include <iostream>
#include "libs/libs4/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Other opertators (+=, +, =)
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* Operator+=

    BoxContainer box1;
    box1.add(1);
    box1.add(2);
    box1.add(3);
    std::cout << "box1: " << box1 << std::endl;

    BoxContainer box2;
    box2.add(10);
    box2.add(20);
    box2.add(30);
    std::cout << "box2: " << box2 << std::endl;

    std::cout << "operator+=: " << std::endl;

    box2 += box1;

    std::cout << "box2: " << box2 << std::endl;
    // box2.add(50);
    // std::cout << "box2: " << box2 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Operator+
    
    std::cout << "operator+: " << std::endl;

    std::cout << "box1: " << box1 << std::endl;
    std::cout << "box2: " << box2 << std::endl;

    BoxContainer box3;
    box3.add(81);
    box3.add(82);

    std::cout << "box3: " << box3 << std::endl;

    std::cout << "box1 + box3: " << (box1 + box3) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Operator=
    
    std::cout << "operator=: " << std::endl;

    std::cout << "box1: " << box1 << std::endl;
    std::cout << "box2: " << box2 << std::endl;
    std::cout << "box3: " << box3 << std::endl;

    box3 = box2;

    std::cout << "box1: " << box1 << std::endl;
    std::cout << "box2: " << box2 << std::endl;
    std::cout << "box3: " << box3 << std::endl;

    //* Note: the string class form the C++ STD library use the same mechanisms 
    std::string data;

    //* examples, refer to the cpp reference 
    data.capacity();
    data.size();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
