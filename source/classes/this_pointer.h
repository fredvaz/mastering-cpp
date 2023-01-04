/*

The C++20 Masterclass: The This pointer

General Notes:
        The expression this is a prvalue expression whose value is the address of the implicit
        object parameter (object on which the non-static member function is being called).

        In other words, this pointer is a special pointer that is maintained by the C++ system and
        it is going to be pointing to the current object that is being manipuled by the C++ arround time.

   [REF]:
    https://en.cppreference.com/w/cpp/language/this
*/
#include <string_view>

#define Test3

using namespace std;

class Dog
{
private:
    string name;
    string breed;
    int *p_age{nullptr};

public:
    Dog() = default;
    Dog(string_view name_param, string_view breed_param, int age_param);
    ~Dog();

    void print_info()
    {
        cout << "Dog (" << this << ") : [ name : " << name
             << " breed : " << breed << " age : " << *p_age << "]" << endl;
    }

    // Setters
#ifdef Test1
    void set_dog_name(string_view name)
    {
        //name = name; // This does nothing because the Compiler cannot differentiate which name
        // variable is to be called if the "string_view name" of the function set_dog_name
        // or if the "string name" member variable of the Class
        this->name = name;
    }
    void set_dog_breed(string_view breed)
    {
        this->breed = breed;
    }
    void set_dog_age(int age)
    {
        *(this->p_age) = age; // We must use the Dereference operator with the curved braces because it is a pointer
    }
#endif

#ifdef Test2 // Chained calls using pointers : Return the Object as a pointer
    Dog *set_dog_name(string_view name)
    {
        this->name = name;
        return this;
    }
    Dog *set_dog_breed(string_view breed)
    {
        this->breed = breed;
        return this;
    }
    Dog *set_dog_age(int age)
    {
        *(this->p_age) = age;
        return this;
    }
#endif

#ifdef Test3 // Chained calls using references : Returning the Object memory address
    Dog &set_dog_name(string_view name)
    {
        this->name = name;
        return *this;
    }
    Dog &set_dog_breed(string_view breed)
    {
        this->breed = breed;
        return *this;
    }

    Dog &set_dog_age(int age)
    {
        *(this->p_age) = age;
        return *this;
    }
};
#endif

Dog::Dog(string_view name_param, string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;

    // at the memory address where the object was constructed
    cout << "Dog constructor called for " << name << " at " << this << endl;
}

Dog::~Dog()
{
    delete p_age;

    // at the memory address where the object was constructed
    cout << "Dog destructor called for " << name << " at " << this << endl;
}

#ifdef Test1
void test1()
{
    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    dog1.set_dog_name("Pumba");
    dog1.set_dog_breed("Wire Fox Terrier");
    dog1.set_dog_age(4);
    dog1.print_info();

    cout << "Done!" << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Return the Object as a pointer allows to set in one go what we did above
    */

    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    // Chained calls using pointers because each Class method returns the Object pointer
    // The compiler will the recongnize it, and if we use the "." do reference it change automatically
    // to the arrow operator "->" (since it is a pointer/memory address)
    dog1.set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);
    dog1.print_info();

    cout << "Done!" << endl;
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: Return the Object as a References allows to use only "." operator
    */

    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    dog1.set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier").set_dog_age(4);
    dog1.print_info();

    cout << "Done!" << endl;
}
#endif