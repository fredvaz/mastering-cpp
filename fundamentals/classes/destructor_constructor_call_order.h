/*

The C++20 Masterclass: Order of Constructor and Destructor Calls

General Notes:
    First will all the Constructors and in the Main program end it will call the Destructors 
    in the reverse order, the compiler does this because the first Constructor might have other
    dependencies from the others Objects

   [REF]:
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

Dog::~Dog()
{
    delete p_age;
    cout << "Dog destructor called for : " << name << endl;
}

#ifdef Test1
void test1()
{
    Dog dog1("Dogyy1", "Shepherd", 2);
    Dog dog2("Dogyy2", "Shepherd", 3);
    Dog dog3("Dogyy3", "Shepherd", 5);
    Dog dog4("Dogyy4", "Shepherd", 1);

    cout << "Done!" << endl;
}
#endif