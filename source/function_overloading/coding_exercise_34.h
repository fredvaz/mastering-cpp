/*

The C++20 Masterclass: Coding Exercise 34

   [REF]:
*/
#include <cstring>
#include <string>

#define Test1

using namespace std;

double add(double a, double b)
{
    return a + b;
}

string add(string &a, string &b)
{
    return a + b;
}

const char *add(char *a, const char *b)
{
    return strcat(a, b);
}

void stitch_them()
{
    char name[20]{"The sky"};
    auto result_str = add(name, " is blue");
    cout << "result_str : " << result_str;
}

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    stitch_them();
}
#endif