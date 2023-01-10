/*

The C++20 Masterclass: Input and Output parameters

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

            Test Case: 
*/

void max_str(const std::string &input1, const std::string input2, std::string &output)
{
    if (input1 > input2)
    {
        output = input1;
    }
    else
    {
        output = input2;
    }
}

int main()
{
    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    std::string out_str;
    std::string string1("Cassablanca");
    std::string string2("Bellevue");

    max_str(string1, string2, out_str);

    std::cout << "max_str : " << out_str << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: 
*/

void max_int(int input1, int input2, int &output)
{
    if (input1 > input2)
    {
        output = input1;
    }
    else
    {
        output = input2;
    }
}

int main()
{
    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    int out_int;
    int in1{45};
    int in2{723};

    max_int(in1, in2, out_int);

    std::cout << "max_int : " << out_int << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: 
*/

void max_double(double input1, double input2, double *output)
{
    if (input1 > input2)
    {
        *output = input1;
    }
    else
    {
        *output = input2;
    }
}

int main()
{
    cout << "------------------------------ Test Case 3 -------------------------------------" << endl;

    double out_double;
    double in_double1{45.8};
    double in_double2{76.9};

    max_double(in_double1, in_double2, &out_double);

    std::cout << "max_double : " << out_double << std::endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//