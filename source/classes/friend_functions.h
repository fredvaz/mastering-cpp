/*

The C++20 Masterclass: Friend Functions

General Notes:
        The friend declaration appears in a class body and grants a function
        or another class access to private and protected members of the class
        where the friend declaration appears.

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
    // Friend functions are not member functions
    friend void debug_dog_info(const Dog &d);
    friend void debug_dog_info();

};

void debug_dog_info(const Dog &d)
{
    cout << "Dog [name : " << d.m_name << ", age : " << d.m_age << "]" << endl;
}

void debug_dog_info()
{
    Dog dog1("Milou", 3);
    dog1.m_name = "Fluffly";
    cout << "Dog [name : " << dog1.m_name << ", age : " << dog1.m_age << "]" << endl;
}

#ifdef Test1
void test1()
{
    Dog dog1("Fluffy", 4);

    debug_dog_info(dog1);

    debug_dog_info();
}
#endif