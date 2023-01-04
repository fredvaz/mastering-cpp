/*

The C++20 Masterclass: Destructor

General Notes:
        Destructors fulfill the opposite functionality of constructors: They are responsible for
        the necessary cleanup needed by a class when its lifetime ends.
        A destructor is a special member function that is called when the lifetime of an object ends.
        The purpose of the destructor is to free the resources that the object may have acquired
        during its lifetime.

   [REF]:
    https://cplusplus.com/doc/tutorial/classes2/
    https://en.cppreference.com/w/cpp/language/destructor

*/
#include <string_view>

#define Test1

using namespace std;

class Dog
{
public:
    Dog() = default;
    Dog(string_view name_param, string_view breed_param, int age_param);
    ~Dog();

private:
    string name;
    string breed;
    int *p_age{nullptr};
};

Dog::Dog(string_view name_param, string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Dog constructor called for " << name << endl;
}

// Destructor : Not possible to pass paramters to the Destructor, it will generate a Compiler error
Dog::~Dog()
{
    // This will release the memonry allocated to p_age pointer in the Constructor
    delete p_age;
    cout << "Dog destructor called for : " << name << endl;
}

#ifdef Test1

void test1()
{
    Dog my_dog("Fluffy", "Shepherd", 2);

    cout << "Done!" << endl;
    // Destructor called in the Program main function end
}
#endif

#ifdef Test2

void some_func()
{
    Dog my_dog("Fluffy", "Shepherd", 2);
}

void test2()
{
    some_func(); // Destructor called in functions end

    cout << "Done!" << endl;
}
#endif

#ifdef Test3
void some_func(Dog dog_param) // The Destructor will be called here because we are passing a copy/by value
{
}

void test3()
{
    Dog dog("Fluffy", "Shepherd", 2);

    some_func(dog);

    cout << "Done!" << endl;
}
#endif

#ifdef Test4
void some_func()
{
    Dog *p_dog = new Dog("Fluffy", "Shepherd", 2);
    // In this case we need to explicitly release the memory for the point in order to the Destructor
    // be called
    delete p_dog;
}

void test4()
{
    some_func();

    cout << "Done!" << endl;
}
#endif