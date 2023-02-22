/*

The C++20 Masterclass: operator overloading -> subscript operator for collections types

General Notes:
        Customizes the C++ operators for operands of user-defined types.


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
    Notes:  #define EXAMPLE_1

            EXAMPLE: subscript operator for collections types
*/

class Scores{
    public : 
        Scores() = delete;
        Scores(const std::string& course_name)
            : m_course_name{course_name}
        {

        }

    // 


    void print_info()const{
        std::cout << m_course_name << " : [ ";
        for(size_t i{}; i < 20; ++i){
            std::cout << m_scores[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    private: 
        std::string m_course_name;
        double m_scores[20]{};
};

double& Scores::operator[](size_t index){
    assert((index >= 0) &&(index < 20));
    return m_scores[index];
 }

double Scores::operator[](size_t index) const{
    assert((index >= 0) &&(index < 20));
    return m_scores[index];
}

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END


    /*
    double& operator[](size_t index){
        assert((index >= 0) &&(index < 20));
        return m_scores[index];
    }
    double operator[](size_t index) const{
        assert((index >= 0) &&(index < 20));
        return m_scores[index];
    }
    */

    // double& operator[](size_t index);
    // double operator[](size_t index) const;