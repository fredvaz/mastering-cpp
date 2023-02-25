/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
       *Customizes the C++ operators for operands of user-defined types.


   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note:  #define EXAMPLE_1

            *EXAMPLE: subscript operator for collections types
*/

class Scores
{

public:
    Scores() = delete; //! delete keyword, because this constructor it will not make any thing usefull
    Scores(const std::string &course_name)
        : m_course_name{course_name}
    {
    }
    ~Scores() = default;

    //* Subscript operator for collection types
    double &operator[](size_t index);
    double operator[](size_t index) const;

    void print_info() const //! Reminder: marked as const because the method will not change any member of the Class
    {
        std::cout << m_course_name << ": [ ";
        for (size_t i{}; i < 20; ++i)
        {
            std::cout << m_scores[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

private:
    std::string m_course_name;
    double m_scores[20]{};
};

//* Subscript operator for collection types
double &Scores::operator[](size_t index)
{
    assert((index > 0) && (index < 20)); //! Proctection to not access out of the index range
                                         //! since our member m_scores[20] is an array of size 20
    return m_scores[index];
}

//* Working with const objects
//! We must do a const overload over our member method whitout returning a Reference
//! because we are not able to changed the member variable
double Scores::operator[](size_t index) const
{
    assert((index > 0) && (index < 20));
    return m_scores[index];
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Scores math("Dummy Object");
    math.print_info();

    math[5] = 66.5;
    math.print_info();

    //* Working with const objects
    //! We must do a const overload over our member method
    const Scores geo("Geography");

    std::cout << "geo [5]: " << geo[5] << std::endl;
    // geo[5] = 55.8; //! Compiler error, we are not able to modify the variable

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END