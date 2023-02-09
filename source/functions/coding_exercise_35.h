/*

The C++20 Masterclass: From Fundamentals to Advanced

General Notes from cplusplus.com:


   [REF]:
*/

#define Test1

using namespace std;

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

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    do_work(10);
}
#endif
