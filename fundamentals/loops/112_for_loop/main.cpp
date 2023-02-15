/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


using namespace std;


/*  */
void test1() 
{
    
    for (unsigned int i{0}; i < 10; ++i)
    {
        cout << i << ": I love C++!" << endl;
    }
    cout << "Loop done!" << endl;

}
/*  */
void test2() 
{
    // Scope of the iterator
    for (size_t i{0}; i < 10; ++i)
    {
        cout << i << ": I love C++!" << endl;
    }
    cout << "Loop done!" << endl;
    cout << "sizeof(size_t): " << sizeof(size_t) << endl;
    //cout << "i: " << i << endl; // The variable i is not in scope

}
/*  */
void test3() 
{
    // Iterator declared outside the loop
    size_t i{0};

    // Better approach! Don't hard code values: It is bad design!
    const size_t COUNT{10};

    for (i; i < COUNT; ++i)
    {
        cout << i << ": I love C++!" << endl;
    }
    cout << "Loop done!" << endl;
    cout << "i: " << i << endl; // The variable i is now acessible

}
/*  */
void test4() 
{
    const size_t COUNT{100};
    unsigned int sum{};

    cout << "Sum!" << endl;
    
    for(size_t i; i < COUNT; i++)
    {
        sum += i;
    }
    cout << "SUM: " << sum << endl;
    cout << "Done!" << endl;
}


int main()
{
    
    // Notes: For Loop
    // size_t : Not a type, just a type alias for some unsigned int representation usualy used as iterator in the For Loop
    // Only can represent positive numbers
    

    cout << "\nTest 1:" << endl;
    test1();

    cout << "\nTest 2:" << endl;
    test2();

    cout << "\nTest 3:" << endl;
    test3();

    cout << "\nTest 4:" << endl;
    test4();

    cout << endl;
    return 0;
}
