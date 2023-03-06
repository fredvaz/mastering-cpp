/*

The C++20 Masterclass Section 44: Class Templates

General Notes:
        A class template defines a family of classes.

        A class template by itself is not a type, or an object, or any other entity. No code is generated
        from a source file that contains only template definitions. In order for any code to appear
        a template must be instantiated: the template arguments must be provided so that the compiler
        can generate an actual class (or function, from a function template).

   [REF]:
    https://en.cppreference.com/w/cpp/language/class_template

*/
#include <iostream>
#include "libs/libs1/boxcontainer.hpp"

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Your first class template / declaration
            * Class template is class blueprint that can be used by the compiler to generate more
            * specific class instances that we can use directly in our code
            * - The definitions should show up in the header file and the reason is the compiler is only
            * going to look in the header files to look what is going to generate template instances for
            * - A template is only instatiated once, it is reused every time the type is needed in the code
            * - Also, all the class members are inline by default, so, we are safe from OFDR issues if the
            * temaplate header is included in many files
            * - Only methods that are used are instantiated
*/

class Point
{
    friend std::ostream &operator<<(std::ostream &out, const Point &operand);

public:
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    // The default constructor must be there for bags of Points to be able
    // initializable with the new T[] statement in the BoxContainer<T> constructor.
    Point() : m_x(0.0), m_y(0.0)
    {
    }

private:
    double m_x{};
    double m_y{};
};

std::ostream &operator<<(std::ostream &out, const Point &operand)
{
    out << "Point [ x: " << operand.m_x << ", y: " << operand.m_y << "]";
    return out;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* int

    std::cout << "BoxContainer of int: " << std::endl;

    BoxContainer<int> int_box;

    int_box.add(33);
    int_box.add(44);
    std::cout << "int_box: " << int_box << std::endl;

    //* double

    std::cout << "BoxContainer of double: " << std::endl;

    BoxContainer<double> double_box;

    double_box.add(100.11);
    double_box.add(200.22);
    std::cout << "double_box: " << double_box << std::endl;

    //* Point

    std::cout << "BoxContainer of Point: " << std::endl;

    BoxContainer<Point> point_box;

    point_box.add(Point(20.1, 20.2));
    point_box.add(Point(200.22, 300.33));

    std::cout << "point_box: " << point_box << std::endl;

    //* std::string

    std::cout << "BoxContainer of std::string" << std::endl;

    BoxContainer<std::string> string_box;

    string_box.add("Hello");
    string_box.add("World");
    std::cout << "string_box: " << string_box << std::endl;

    //* char

    std::cout << "BoxContainer of char" << std::endl;

    BoxContainer<char> char_box;

    char_box.add('H');
    char_box.add('e');
    char_box.add('l');
    char_box.add('l');
    char_box.add('o');
    char_box.add('o');
    std::cout << "char_box: " << char_box << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << "Trying out all the methods: " << std::endl;

    BoxContainer<int> int_box1;
    int_box1.add(10);
    int_box1.add(21);
    int_box1.add(44);

    std::cout << "int_box1: " << int_box1 << std::endl;
    int_box1.add(10);
    int_box1.add(55);
    int_box1.add(10);
    std::cout << "int_box1: " << int_box1 << std::endl;

    int_box1.remove_item(55);
    std::cout << "int_box1: " << int_box1 << std::endl;

    size_t removed = int_box1.remove_all(10);

    std::cout << removed << " items removed" << std::endl;
    std::cout << "int_box1: " << int_box1 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Copy construct

    std::cout << "Copy construction" << std::endl;

    BoxContainer<int> int_box2(int_box);

    std::cout << "int_box: " << int_box << std::endl;
    std::cout << "int_box2: " << int_box2 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Copy assign

    std::cout << "Copy assignment" << std::endl;

    int_box2 = int_box1;

    std::cout << "int_box1: " << int_box1 << std::endl;
    std::cout << "int_box2: " << int_box2 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << "operator+=: " << std::endl;

    int_box2 += int_box;

    std::cout << "int_box: " << int_box << std::endl;
    std::cout << "int_box2: " << int_box2 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << "operator+" << std::endl;

    BoxContainer<int> int_box3;
    int_box3.add(100);
    int_box3.add(200);

    BoxContainer<int> int_box4;

    int_box4 = int_box2 + int_box3;

    std::cout << "int_box4: " << int_box4 << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            * EXAMPLE: Quiz 82
*/

template <typename T, typename P>
struct Map
{
    T m_key;
    P m_value;
    Map(T key, P value)
        : m_key(key), m_value(value)
    {
    }
    void print_info() const
    {
        std::cout << "key: " << m_key << ", value: " << m_value << std::endl;
    }
    ~Map() {}
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    Map map1(111222, std::string{"Steve Murphy"});

    std::cout << "key: " << map1.m_key << std::endl;
    std::cout << "value: " << map1.m_value << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//
