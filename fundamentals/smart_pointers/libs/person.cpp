
//

#include "person.hpp"
#include "dog.hpp"

//

Person::Person(std::string name) : m_name{name}
{
}

void Person::adopt_dog( std::unique_ptr<Dog> dog){
    std::cout << m_name << " just adopted the dog " << dog->get_name() << std::endl;
}


Person::~Person()
{
   
}