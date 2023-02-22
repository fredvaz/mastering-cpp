/*

The C++20 Masterclass:

General Notes:


   [REF]:
   
*/
#include "dog_aux.hpp"

Dog::Dog(const std::string &name_param, const std::string &breed_param, unsigned int age_param)
{
    m_name = name_param;
    m_breed = breed_param;
    m_age = age_param;
}

// Getters
/* std::string Dog::get_name() const
{
    return this->m_name;
}

std::string Dog::get_breed() const
{
    return m_breed;
}

unsigned int Dog::get_age() const
{
    //m_age = 6; // Comipler error: assignment of member 'Dog::m_age' in read-only object
    // once we are set the member function with the falg const
    return m_age;
} */

// Setters
void Dog::set_name(std::string name_param)
{
    m_name = name_param;

}
void Dog::set_breed(std::string breed_param)
{
    m_breed = breed_param;
}
void Dog::set_age(unsigned int age)
{
    m_age = age;
}

void Dog::print_info() const
{
    ++m_print_info_count; // mutable keyword For debug purposes but not recommned
    std::cout << "Dog (" << this << ") : [ name: " << this->m_name 
              << ", breed: " << this->m_breed                      
              << ", age: " << this->m_age 
              << ", print_count : "<< m_print_info_count << " ]" << std::endl;    
}