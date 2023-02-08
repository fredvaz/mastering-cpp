/*

The C++20 Masterclass: Derived classes / Classes Inheritance 

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
#include "player.cpp"
#include "nurse.cpp"
#include "engineer.cpp"
#include "civilengineer.cpp"

//#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes: Private members : Player Class cannot acess the private members of Class Person
    */

    Player p1("Basketball");
    p1.set_first_name("Frederico");
    p1.set_last_name("Vaz");

    cout << "player : " << p1 << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes: Protected members : Only Player Class can acess the private members of Class Person
    */

    Player p1("Basketball", "Frederico", "Vaz");
    // Now we don't need acess ther member variables using the methods functions because
    // the Player casses has protected access to he member variable of the Person Class
    cout << "player : " << p1 << endl;

    // Still we cannot direct acess externally the private members of the Base Class Person
    //p1.first_name = "Daniel"; // Compiler Error
}
#endif

#ifdef Test3
void test3()
{
    /*
    Notes: Private members : Base class access specifiers
    */
    Person person1("Daniel Gray", 27, "Blue Sky St 233 #56");
    cout << "person1 : " << person1 << endl;

    person1.m_full_name;
    //person1.m_age; // Compiler Error : Protected member CANNOT be acessed outside of the Base Class

    /* -------------------------------------------------------------------------------*/
    // Player class will do public inheritance

    Player player;

    player.m_full_name = "Samuel Jackson"; // Public member of the Derivated class
    //player.m_age = 55; // Compiler error : Protected member is acessible inside the Derivated Class
    // but not from outisde of the class
    //player.m_address = "2i892317322"; // Compiler : Private member is neither acessible
    // inside the derivated class or Outside of the Class

    /* -------------------------------------------------------------------------------*/
    // Nurse class will do protected inheritance

    Nurse nurse1;

    //nurse1.m_full_name = "Davy Johnes"; // Compiler error : Now is Protected member in the Derivated class
    //nurse1.m_age = 51; // Compiler error : Still Protected member

    /* -------------------------------------------------------------------------------*/
    // Engineer class is doing private inheritance

    Engineer engineer1;

    //engineer1.m_full_name = "Olivier Godson"; // Compiler error : Now is Private member in the Derivated class
    //engineer1.m_age = 55; // Compiler error : Now is Private member in the Derivated class
    //engineer1.m_address = "dsakfd;aslfjd;laskf"; // Compiler error : Still Private member

    /* -------------------------------------------------------------------------------*/
    // 403 : Closing in on Private Inheritance

    // CivilEngineer class is doing private inheritance from Engineer class
    // But the Engineer class is already private inheritance, so, it will selfish

    CivilEngineer civilengineer1;

    //engineer1.m_full_name = "Olivier Godson"; // Compiler error : Already Private member in the Base Class
}
#endif


#ifdef Test4
void test4()
{
    /*
    Notes: Private members : Resurecting members back in context
    */
}
#endif

#ifdef Test5
void test5()
{
    /*
    Notes: Private members : Default Constructors with Inheritance

           Constructors called order : Person -> Engineer -> CivilEngineer

           Starts froms the most basic going down to the most specialized one
    */
    CivilEngineer ce1;

    cout << "Hello!" << endl;
}
#endif

#define Test6
#ifdef Test6
void test6()
{
    /*
    Notes: Private members : Custom Constructors with Inheritance

           Constructors parameters forward from the Derivated to Base class

           Use of the initializer lists with Constructors whose job is going to be to 
           initialize these member varaibles
    */
    cout << "----------------------------------------" << endl;

    Person person1("John Snow", 27, "Winterfell Cold 33St#75");
    cout << "person1 : " << person1 << endl;

    cout << "----------------------------------------" << endl;

    Engineer engineer1("John Snow", 27, "Winterfell Cold 33St#75", 12);
    cout << "person1 : " << engineer1 << endl;

    cout << "----------------------------------------" << endl;

    CivilEngineer civilengineer1("John Snow", 27, "Winterfell Cold 33St#75", 12, "Bridges");
    cout << "person1 : " << civilengineer1 << endl;

    cout << "----------------------------------------" << endl;
}
#endif

#define Test7
#ifdef Test7
void test7()
{
    /*
    Notes: Private members : Copy Constructors with Inheritance

           Constructors parameters copy from a class Object another Object of the same type
    */
    cout << "----------------------------------------" << endl;

    // Engineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12);

    //  cout << "----------------------------------------" << endl;
    // // By Default the Compiler accepts this operation:
    // // Is going take out the contract count from engineer one an copy that into engineer to
    // Engineer eng2(eng1);

    // cout << "eng2 : " << eng2 << endl;

    cout << "----------------------------------------" << endl;

    CivilEngineer eng1("Daniel Gray", 41, "Green Sky Oh Blue 33st#75", 12, "Bridges");

    cout << "eng2 : " << eng1 << endl;

    cout << "----------------------------------------" << endl;

    CivilEngineer eng2(eng1);

    cout << "eng2 : " << eng2 << endl;

    cout << "----------------------------------------" << endl;
}
#endif