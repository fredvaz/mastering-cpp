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

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: Friend functions for class templates
            * - functions that can take private members of our template class
            * In this example, we will review the friend functions that take a parameter (or more) of
            * our template class. The goal is so that we are able to model an operator<< for our
            * template class
*/

template <typename T>
class TemplateClass; //* forward declare to make function declaration possible

template <typename T>
void some_func(TemplateClass<T>); //* declaration . Func is a template function because it has
                                  //* template<typename T> in front of it, the compiler will
                                  //* generate an instance for it with concrete types as template
                                  //* arguments when needed.

template <typename T>
class TemplateClass
{
    friend void some_func<T>(TemplateClass<T> param); //* friend function

public:
    explicit TemplateClass<T>()
    {
    }
    void set_up(T param)
    {
        m_var = param;
    }
    void do_something(const T a, T b)
    {
        std::cout << "Doing something with " << a << " and " << b << std::endl;
    }

private:
    T m_var;
};

//* friend function
template <typename T> 
void some_func(TemplateClass<T> param)
{
    std::cout << "Inside some_func, accessing private data of TemplateClass: "
              << param.m_var << std::endl;
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    TemplateClass<int> object1;
    object1.set_up(10);

    TemplateClass<double> object2;
    object2.set_up(12.2);

    some_func(object1);
    some_func(object2);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
