/*

The C++20 Masterclass: Friend Classes

General Notes:
        The friend declaration appears in a class body and grants a function or another class 
        access to private and protected members of the class where the friend declaration appears.

   [REF]:
    https://en.cppreference.com/w/cpp/language/friend
    https://cplusplus.com/doc/tutorial/inheritance/
*/

#define Test1

using namespace std;

class Dog
{
private:
    string m_name;
    int m_age;

public:
    Dog(const string &name, int age)
        : m_name{name}, m_age{age}
    {
    }
    // Friend Class : Allows access to the private members of Dog Class
    // The workarround is mark these members as public but we have seen that this is really bad design
    // The option is to give the Cat class acess to our own private member variables
    friend class Cat;
};

class Cat
{
private:
    string m_name{"Pompeu"};

public:
    void print_dog_info(const Dog &d)
    {
        cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "]" << endl;
        cout << "Cat [ name : " << this->m_name << "]" << endl;

    }
};

#ifdef Test1
void test1()
{
    Cat cat1;
    Dog dog1("Fluffly", 2);

    cat1.print_dog_info(dog1);
}
#endif