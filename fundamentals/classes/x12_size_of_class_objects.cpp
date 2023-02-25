/*

The C++20 Masterclass: Size of Class Objects

General Notes:
    The size of a  Class is going to be the sum of the size of the member variables
    the size of the member functions/methods it will not count

   [REF]: No
*/
#include <iostream>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE:
*/

class Dog
{
public:
    Dog() = default;
    void print_info()
    {
    }
    void do_something()
    {
    }

private:
    size_t leg_count; // 8 bytes
    size_t arm_count; // 8 bytes
    int *p_age;       // 8 bytes
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Dog dog1;
    // The size is going to be the sum of the size of  the member variables
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int *) << std::endl;
    std::cout << "sizeof(Dog) : " << sizeof(Dog) << std::endl;

    // The size of the string object will be the same regardless the size
    // of the characters used, because its pointing to memmory address
    // that eventually it will eventually sequential follows all the chars
    std::string name{"I am the king of the universe!"};
    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
