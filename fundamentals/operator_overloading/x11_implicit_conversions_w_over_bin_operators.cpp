/*

The C++20 Masterclass Section 38: Operator Overloading

General Notes:
        *Customizes the C++ operators for operands of user-defined types.
        !When a binary operator is implemented as a member function, the left operand is never
        !implicity converted

   [REF]:
    https://en.cppreference.com/w/cpp/language/operators

*/
#include <iostream>

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            *EXAMPLE: Implicit Conversions with Overriden Binary Operators
*/

class Number
{
    friend std::ostream &operator<<(std::ostream &out, const Number &number);

    // Arithmetic operators
    // friend Number operator+(const Number &left_operand, const Number &right_operand); //*
    friend Number operator-(const Number &left_operand, const Number &right_operand);
    friend Number operator*(const Number &left_operand, const Number &right_operand);
    friend Number operator/(const Number &left_operand, const Number &right_operand);
    friend Number operator%(const Number &left_operand, const Number &right_operand);

public:
    Number() = default;
    ~Number();
    Number(int value);
    // explicit Number(int value); //! Line 65 fails is the member declared explicit

    // Custom type conversions from "int" Number object to a double
    explicit operator double() const
    {
        return (static_cast<double>(m_wrapped_int));
    }

    //* Added operator+ as a member
    //! Implicit conversion won't work for the first operand
    Number operator+(const Number &right) const
    {
        return Number(m_wrapped_int + right.m_wrapped_int);
    }

    // getter
    int get_wrapped_int() const
    {
        return m_wrapped_int;
    }

private:
    int m_wrapped_int{0};
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Number num1(15);

    std::cout << "num1: " << num1 << std::endl;

    //* OK if no declared explicit : the literal 2 will implicit converted to a Number object
    std::cout << "num1 + num2: " << (num1 + 2) << std::endl;

    //! Implicit conversion will not work in the first below example
    // std::cout << "2 + num1:" << 2 + num1 << std::endl; //! no operator "+" matches these operands (operand types are ‘int’ and ‘Number’)
    std::cout << "2 - num1:" << 2 - num1 << std::endl; //* OK, because the operator- is a non-member
    //! The point is: if you want to support implicit conversions for your binary operators, you
    //! should do them as non-member free-standing global functions as we are doing before


    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

//* Solution: Added the operator+ as a non-member free standing function
// Number operator+(const Number &left_operand, const Number &right_operand)
// {
//     return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);
// }

//

Number::Number(int value) : m_wrapped_int(value)
{
}

std::ostream &operator<<(std::ostream &out, const Number &number)
{
    out << "Number: [" << number.m_wrapped_int << "]";
    return out;
}

Number::~Number()
{
}

Number operator-(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);
}

Number operator*(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);
}

Number operator/(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);
}

Number operator%(const Number &left_operand, const Number &right_operand)
{
    return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);
}

#endif // EXAMPLE_1 END
