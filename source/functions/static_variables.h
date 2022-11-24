/*

The C++20 Masterclass: Global vs Static variables

-   Both global and static variables have static storage duration. 
    They live throughout the entire lifetime of the program

-   Static variables are scoped to the function in which they are 
    declared and used. If you try to access them outside that function
    you will get a compiler error

-   Global variables are scoped to the global scope of the file where
    they are declared. They are accessible and usable throught out the
    entire file

*/
#include <iostream>

#define Test1

using namespace std;

size_t dog_count{0}; // Global scope

unsigned int add_student()
{
    static int student_count{0}; // The scope of this variale is in add_student
                                 // but it's life times goes beyond the function execution

    student_count++;
    dog_count++; // Variables lives in the Global scope
    return student_count;
}

unsigned int add_student2()
{
    int student_count{0};
    student_count++;
    return student_count;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    cout << "student count : " << add_student() << endl; // student_count : 1
    cout << "student count : " << add_student() << endl; // student_count : 2
    cout << "student count : " << add_student() << endl; // student_count : 3
    // VS NON-STATIC Variable
    for (size_t i = 0; i < 3; i++)
    {
        cout << "student count 2 : " << add_student2() << endl;
    }
    
}
#endif

#ifdef Test2

void do_something()
{
    student_cout; // The variable is only on the scope of the add_student
                  // Therefore not accesible to others functions
}
#endif

#ifdef Test3
/*                                           Conding exercise 35                                 */
void func()
{

    static unsigned int count{0};
    count++;
    cout << count << " ";
}

void do_work(unsigned int n)
{
    for (unsigned int i{0}; i < n; ++i)
    {
        func();
    }
}
#endif

#ifdef Test4
/*                                           Conding exercise 36                                */
int odd()
{
    static int odd{-1};
    odd += 2;
    return odd;
}

void print_odds(unsigned int count)
{
    for (size_t i{0}; i < count; i++)
    {
        std::cout << odd() << " ";
    }
}

void test4()
{
    /*
    Notes:
    */
    print_odds(10);
}
#endif