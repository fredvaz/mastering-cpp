/*

The C++20 Masterclass:

General Notes:


   [REF]:

*/
#ifndef DOG_H
#define DOG_H
// This is going to prevent people from including this twice.
// So the preprocessor is basically going to come in this file and say if this then here is not defined,
// I am going to define it and then I'm going to include whatever I have in this file here.
// If this thing is already defined, it's not going to define this and it's not going to include what
// we have here.

#include <iostream>
#include <string>

class Dog
{

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param);

    // Getters
    std::string_view get_name();
    std::string_view get_breed();
    unsigned int get_age();

    //* EXAMPLE_5
    //! We set the member functions with the const flag because these functions are just to read
    //! information from the class objects
    std::string_view get_name() const;
    std::string_view get_breed() const;
    unsigned int get_age() const;

    // Setters
    void set_name(std::string_view name_param);
    void set_breed(std::string_view breed_param);
    void set_age(unsigned int age);

    // Utility functions
    void print_info();
    
    //* EXAMPLE_5
    void print_info() const;

private:
    // our member variables now have been changed to string_view because we want to avoid copy's
    // when we pass parameters to the constructors here.
    std::string_view m_name;
    std::string_view m_breed;
    unsigned int m_age;
};

#endif // DOG_H

//
