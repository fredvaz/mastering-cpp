/*

The C++20 Masterclass: Derived classes / Copy Constructors with Inheritance

General Notes:
        Any class type (whether declared with class-key class or struct) may be declared
        as derived from one or more base classes which, in turn, may be derived from their
        own base classes, forming an inheritance hierarchy.

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
    https://en.cppreference.com/book/intro/inheritance
    https://cplusplus.com/doc/tutorial/inheritance/

*/
#include <iostream>
#include "constructors_with_inheritance/person.cpp"
#include "constructors_with_inheritance/engineer.cpp"
#include "constructors_with_inheritance/civilengineer.cpp"

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:  #define Test1

            Default Case : By Default the Compiler accepts the below operation with the default
            constructors, but if we want to do some dynamic memory allocation we have to 
            setup or own Copy custom constructor
    */
    cout << "----------------------------------------" << endl;
    Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12);
    cout << "----------------------------------------" << endl;

    Engineer eng2(eng1);
    cout << "eng2 : " << eng2 << endl;
    cout << "----------------------------------------" << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:  #define Test2
    
            Test Case : the Person object class is initialized with the Copy Custom constructor
            supose for example for some memory dynamic memory allocation
            but the Engineer object class is not initialized with the Person object Class
            therefore it will call the Default constructor for Person
           
            Constructors parameters copy from a class Object another Object of the same type
            Is going take out the contract count from engineer one an copy that into engineer to
    */
    cout << "----------------------------------------" << endl;
    Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12);
    cout << "----------------------------------------" << endl;

    Engineer eng2(eng1);
    cout << "eng2 : " << eng2 << endl;
    cout << "----------------------------------------" << endl;
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: #define Test3
           
           Test Case : the Person object class is initialized with the Copy Custom constructor
    */
    cout << "----------------------------------------" << endl;
    Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12);
    cout << "----------------------------------------" << endl;

    // Test Case : Copy Custom constructor Person object class
    // in this case the Person object class is initialized with the Copy Custom constructor
    Engineer eng2(eng1);
    cout << "eng2 : " << eng2 << endl;
    cout << "----------------------------------------" << endl;
}
#endif

#ifdef Test4
void test4()
{
    /*
    Notes: #define Test4
           
           Test Case : now CivilEngineer Constructor has to initialize with the Engineeer Constructor
       
    */
    cout << "----------------------------------------" << endl;
    CivilEngineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12, "Bridges");
    cout << "eng2 : " << eng1 << endl;
    cout << "----------------------------------------" << endl;

    // Test Case : now CivilEngineer Constructor has to initialize with the Engineeer Constructor
    CivilEngineer eng2(eng1);
    cout << "eng2 : " << eng2 << endl;
    cout << "----------------------------------------" << endl;
}
#endif