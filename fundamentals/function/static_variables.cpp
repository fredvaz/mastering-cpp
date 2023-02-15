/*
The C++20 Masterclass: Global vs Static variables


General Notes:
    Both global and static variables have static storage duration. 
    They live throughout the entire lifetime of the program

    Static variables are scoped to the function in which they are 
    declared and used. If you try to access them outside that function
    you will get a compiler error

    Global variables are scoped to the global scope of the file where
    they are declared. They are accessible and usable throught out the
    entire file

   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: 
*/

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

void do_something()
{
    //student_cout; // Compiler error: 'student_cout' was not declared in this scope
                    // The variable is only on the scope of the add_student
                    // Therefore not accesible to others functions
}

int main()
{

    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    cout << "student count: " << add_student() << endl; // student_count : 1
    cout << "student count: " << add_student() << endl; // student_count : 2
    cout << "student count: " << add_student() << endl; // student_count : 3
    
    // VS NON-STATIC Variable
    for (size_t i = 0; i < 3; i++)
    {
        cout << "student count 2: " << add_student2() << endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

//#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Conding exercise 35 
*/

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

int main()
{

    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

// #define EXAMPLE_3
#ifdef EXAMPLE_3
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: Conding exercise 36
*/

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
        cout << odd() << " ";
    }
}

int main()
{

    cout << "------------------------------ EXAMPLE_3 -------------------------------------" << endl;

    print_odds(10);
    cout << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END