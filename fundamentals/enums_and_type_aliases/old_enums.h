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
    Notes: Old Enums or Legacy Enumerated Types
           Enum Classes were introduced in C++11 and introduced a safer
           way to work with enums
           Legacy enums implicity transform to int, which is good for cout
           but that introduces the problem that we can compare different enum
           types which is very confusing
    */
    enum Direction : unsigned char
    {
        TopLeft = 64,
        TopRight,
        Center,
        BottomLeft,
        BottomRight
    };

    enum Tool
    {
        Pen,
        Marker,
        Eraser,
        Rectangle,
        Circle,
        PaintBucket
    };

    Direction direction{Direction::TopLeft};
    Tool tool{Tool::Pen};

    cout << "direction : " << static_cast<unsigned int>(direction) << endl;
    cout << "tool : " << tool << endl;
    // The compiler it will give us a Warnning due the below comparision
    cout << "(tool > direction) : " << (tool > direction) << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
}
#endif