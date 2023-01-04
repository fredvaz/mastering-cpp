/*

The C++20 Masterclass: Size of Class Objects

General Notes:
    The size of a  Class is going to be the sum of the size of the member variables
    the size of the member functions/methods it will not count

   [REF]: No
*/

#define Test1

using namespace std;

class Dog
{
public:
    Dog() = default;
    void print_info()
    {
    }
    void do_something()
    {
    }

private:
    size_t leg_count; // 8 bytes
    size_t arm_count; // 8 bytes
    int *p_age;       // 8 bytes
};

#ifdef Test1
void test1()
{
    Dog dog1;
    // The size is going to be the sum of the size of  the member variables
    cout << "sizeof(size_t) : " << sizeof(size_t) << endl;
    cout << "sizeof(int*) : " << sizeof(int*) << endl;
    cout << "sizeof(Dog) : " << sizeof(Dog) << endl;

    // The size of the string object will be the same regardless the size
    // of the characters used, because its pointing to memmory address 
    // that eventually it will eventually sequential follows all the chars 
    string name{"I am the king of the universe!"};
    cout << "sizeof(name) : " << sizeof(name) << endl;

}
#endif