/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include "dog.hpp"

Dog::Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param)
{
    m_name = name_param;
    m_breed = breed_param;
    m_age = age_param;
}

#ifdef Test5
// Getters
std::string_view Dog::get_name() const
{
    return this->m_name;
}

std::string_view Dog::get_breed() const
{
    return m_breed;
}

unsigned int Dog::get_age() const
{
    //m_age = 6; // Comipler error: assignment of member 'Dog::m_age' in read-only object
    // once we are set the member function with the falg const
    return m_age;
}

#else
// Getters
std::string_view Dog::get_name()
{
    //return m_name;
    return this->m_name;
}

std::string_view Dog::get_breed()
{
    return m_breed;
}

unsigned int Dog::get_age()
{
    return m_age;
}

#endif

// Setters
void Dog::set_name(std::string_view name_param)
{
    m_name = name_param;
    //this->m_name = name_param; // the compiler does this in the background
    // usiong the This pointer we can really modify this Object
}
void Dog::set_breed(std::string_view breed_param)
{
    m_breed = breed_param;
}
void Dog::set_age(unsigned int age)
{
    m_age = age;
}

#ifdef Test5
// Utility functions
void Dog::print_info() const
{
    std::cout << "Dog (" << this << ") : [ name : " << this->m_name 
              << ", breed : " << this->m_breed                      
              << ", age : " << this->m_age << " ]" << std::endl;    
}

#else
// Utility functions
void Dog::print_info()
{
    std::cout << "Dog (" << this << ") : [ name : " << m_name // Compiler changes to this->m_name
              << ", breed : " << m_breed                      // this->m_breed
              << ", age : " << m_age << " ]" << std::endl;    // this->m_age
} // therefore we cnannot modify if is a const Object
#endif