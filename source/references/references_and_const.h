/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: References and Const
    */

    // Non const reference
    cout << endl;
    cout << "Non const reference : " << endl;
    int age{27};
    const int &ref_age{age}; // The const applies only to the reference variable
    
    cout << "age : " << age << endl;
    cout << "ref_age : " << ref_age << endl;

    //Can modify original variable through reference
    cout << endl;
    cout << "Modify original variable through reference : " << endl;

    ref_age++; //Mofify the reference is not possible since it is const

    cout << "age : " << age << endl;
    cout << "ref_age : " << ref_age << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */

    // Simulating reference behavior with pointers
    const int *const p_age{&age};
    *p_age = 45;
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: The compiler can see that see tha twe flagged age as const.
    So it will go to great measures to make sure that age variable isn't
    modified in any way. So when the compiler notices the declaration of
    our reference, it notices one could go through the reference and modify
    the referenced variable which is const by design, violating the constness
    of the age variable. The compiler doesn't like that and throws a compiler
    error.
    */

    const int age{33}; // The variable is declared as const
 
    int& age_ref{age}; // The compiler it will fail here
 
    cout << "--Before--" << endl;
    cout << "age_ref: " << age_ref << endl;
    cout << "&age_ref : " << &age_ref << endl;
 
    int age1 {44};
    age_ref = age1;
 
    cout << "--After--" << endl;
    cout << "age_ref: " << age_ref << endl;
    cout << "&age_ref : " << &age_ref << endl;
}
#endif

#ifdef Test4
void test4()
{
    /*
    Notes: Now the compiler sees thar our reference declaration is const and 
    the reference will protect our age constness. If someone tries to go
    through the reference to modify our data. BOOOM! A compiler error will bo
    thrown into your face. This is exacly what will happen in our code snippet.
    */

    const int age{33}; // The variable is declared as cons
 
    const int& age_ref{age}; // The Reference is declared as const too to protect the variable as a const
 
    cout << "--Before--" << endl;
    cout << "age_ref: " << age_ref << endl;
    cout << "&age_ref : " << &age_ref << endl;
 
    int age1 {44};
    age_ref = age1; // The compiler it will fail, because is not possible to change the data since is a const varaible
 
    cout << "--After--" << endl;
    cout << "age_ref: " << age_ref << endl;
    cout << "&age_ref : " << &age_ref << endl;
}
#endif