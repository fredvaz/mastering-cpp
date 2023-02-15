/*

The C++20 Masterclass: Class across mutilple files

General Notes:
        Just to use the directives #include and the pre-processor #ifndef
        The use of the Header files is recommended to the Class definitions, which the part
        of interest to use by others developers. The methods implementation is not so import
        when we only want to use the output of a Class Object from other developer as a Black Box

   [REF]: No
*/
#include "cylinder.cpp"

#define Test1

using namespace std;

#ifdef Test1

void test1()
{
    Cylinder cylinder1(100, 10);

    cout << "volume : " << cylinder1.volume() << endl;
}
#endif