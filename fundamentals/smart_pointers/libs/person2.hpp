#ifndef PERSON_H
#define PERSON_H

//

#include <memory>
#include <string>

//

class Person
{

public:
    Person() = default;
    Person(std::string name);
    ~Person();

    // Member functions
    void set_friend(std::shared_ptr<Person> p)
    {
        //* The assignment creates a weak_ptr out of p
        m_friend = p;
    }

private:
    // std::shared_ptr<Person> m_friend; //! Using the share_ptr the destructors are not called
    //* We must use a Weak pointer here
    std::weak_ptr<Person> m_friend; // Initialized to nullptr
    std::string m_name{"Unnamed"};
};

#endif // PERSON_H

//
