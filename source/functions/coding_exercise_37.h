/*

The C++20 Masterclass: From Fundamentals to Advanced

General Notes from cplusplus.com:


   [REF]:
*/

#define Test1

using namespace std;

unsigned int factorial(unsigned int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    unsigned int n{5};

    cout << n << "! (factorial) : " << factorial(5);
}
#endif