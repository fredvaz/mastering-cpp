/*

The C++20 Masterclass: Passing sized arrays by reference

General Notes:


   [REF]:
   
*/
#include <iostream>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Passing sized arrays by reference
*/

// Passing an Array by reference, it will tell to to compiler to pass a specific Array size
// double sum(const double (&scores)[3])
double sum(const double (&scores)[10])
{
    double sum{};
    for (size_t i{}; i < std::size(scores); ++i) // This way, we can use the size function
    {
        sum += scores[i];
    }
    return sum;
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    // double student_scores[]{10.0, 20.0, 30.0}; // Size of 3 elements
    double student_scores[]{10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 1.0}; // Size of 10 elements

    double sum_result = sum(student_scores);

    cout << "result is : " << sum_result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END