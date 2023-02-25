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
#include <iostream>
#include <string_view>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: The This pointer
*/

class Dog
{

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

    void print_info()
    {
        std::cout << "Dog (" << this << ") : [ name : " << name
                  << " breed : " << breed << " age : " << *p_age << "]" << std::endl;
    }

    // Setters
    void set_dog_name(std::string_view name)
    {
        // name = name; // This does nothing because the Compiler cannot differentiate which name
        //  variable is to be called if the "string_view name" of the function set_dog_name
        //  or if the "string name" member variable of the Class
        this->name = name;
    }
    void set_dog_breed(std::string_view breed)
    {
        this->breed = breed;
    }
    void set_dog_age(int age)
    {
        *(this->p_age) = age; //! We must use the Dereference operator with the curved braces because it is a pointer
    }

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    dog1.set_dog_name("Pumba");
    dog1.set_dog_breed("Wire Fox Terrier");
    dog1.set_dog_age(4);
    dog1.print_info();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            *EXAMPLE: Return the Object as a pointer allows to set in one go what we did above
*/

class Dog
{

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

    void print_info()
    {
        std::cout << "Dog (" << this << ") : [ name : " << name
                  << " breed : " << breed << " age : " << *p_age << "]" << std::endl;
    }

    //* Chained calls using pointers : Return the Object as a pointer
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

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    //* Chained calls using pointers because each Class method returns the Object pointer
    // The compiler will the recongnize it, and if we use the "." do reference it change automatically
    // to the arrow operator "->" (since it is a pointer/memory address)
    dog1.set_dog_name("Pumba")->set_dog_breed("Wire Fox Terrier")->set_dog_age(4);
    dog1.print_info();

    cout << "Done!" << endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;

    std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
}

#endif // EXAMPLE_2 END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    !Note:  #define EXAMPLE_3

            *EXAMPLE: Return the Object as a References allows to use only "." operator
*/

class Dog
{

public:
    Dog() = default;
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    ~Dog();

    void print_info()
    {
        std::cout << "Dog (" << this << ") : [ name : " << name
                  << " breed : " << breed << " age : " << *p_age << "]" << std::endl;
    }

    //* Chained calls using references : Returning the Object memory address
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

private:
    std::string name;
    std::string breed;
    int *p_age{nullptr};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_3 -------------------------------------" << std::endl;

    Dog dog1("Flufy", "Shepherd", 2);
    dog1.print_info();

    dog1.set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier").set_dog_age(4);
    dog1.print_info();

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for " << name << " at " << this << std::endl;
}

Dog::~Dog()
{
    delete p_age;
    std::cout << "Dog destructor called for " << name << " at " << this << std::endl;
}

#endif // EXAMPLE_3 END

//

