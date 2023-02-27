/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include "dog2.hpp"

Dog2::Dog2(std::string_view name_param, std::string_view breed_param, unsigned int age_param)
{
    m_name = name_param;
    m_breed = breed_param;
    m_age = age_param;
}

// Getters
std::string_view Dog2::get_name()
{
    //return m_name;
    return this->m_name;
}

std::string_view Dog2::get_breed()
{
    return m_breed;
}

unsigned int Dog2::get_age()
{
    return m_age;
}

//* EXAMPLE_5
// Getters
std::string_view Dog2::get_name() const
{
    return this->m_name;
}

std::string_view Dog2::get_breed() const
{
    return m_breed;
}

unsigned int Dog2::get_age() const
{
    //m_age = 6; //! Comipler error: assignment of member 'Dog2::m_age' in read-only object
    //! once we are set the member function with the falg const
    return m_age;
}

// Setters
void Dog2::set_name(std::string_view name_param)
{
    m_name = name_param;
    //this->m_name = name_param; // the compiler does this in the background
    // usiong the This pointer we can really modify this Object
}
void Dog2::set_breed(std::string_view breed_param)
{
    m_breed = breed_param;
}
void Dog2::set_age(unsigned int age)
{
    m_age = age;
}

// Utility functions
void Dog2::print_info()
{
    std::cout << "Dog (" << this << ") : [ name: " << m_name // Compiler changes to this->m_name
              << ", breed: " << m_breed                      // this->m_breed
              << ", age: " << m_age << " ]" << std::endl;    // this->m_age
} // therefore we cnannot modify if is a const Object


//* EXAMPLE_5
// Utility functions
void Dog2::print_info() const
{
    std::cout << "Dog (" << this << ") : [ name: " << this->m_name 
              << ", breed: " << this->m_breed                      
              << ", age: " << this->m_age << " ]" << std::endl;    
}

//
