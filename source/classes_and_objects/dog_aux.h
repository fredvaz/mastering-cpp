/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog
{
public:
    Dog() = default;
    Dog(const std::string &name_param, const std::string &breed_param, unsigned int age_param);

    // Getter that work as Setter too: returns the reference/address of the varaible
    std::string &name()
    {
        std::cout << "non-const method called..." << std::endl;
        return m_name;
    }

    // Overload the getter returning const reference to be compatible wiht const objects
    // This would make our Class usable with const object and non-const objects
    const std::string &name() const
    {
        std::cout << "const method called..." << std::endl;
        return m_name;
    }

    std::string &breed()
    {
        return m_breed;
    }

    const std::string &breed() const
    {
        return m_breed;
    }

    const unsigned int &age() const
    {
        return m_age;
    }

    // Getters
    // std::string get_name() const;
    // std::string get_breed() const;
    // unsigned int get_age() const;

    // Setters
    void set_name(std::string name_param);
    void set_breed(std::string breed_param);
    void set_age(unsigned int age);

    // Utility functions
    void print_info() const;
    
    const std::string &compile_dog_info() const
    {
        std::string dog_info = "dog name: " + m_name 
                            + "dog_breed: " + m_breed;
                            + "dog_age: " + m_age;
        return dog_info; // Dagling reference: we are returning a reference to a local variable
    }

    unsigned int *jumps_per_minute() const
    {
        unsigned int jumps{10};
        return &jumps; // Dangling pointer: we returning a pointer to a local variable
    }

private:
    std::string m_name;
    std::string m_breed;
    unsigned int m_age;
    mutable size_t m_print_info_count{0}; // Allows to modify a const member, use not recommed
                                         // unless for debug purpose only
};

#endif // DOG_H