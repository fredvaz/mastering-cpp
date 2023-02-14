/*

The C++20 Masterclass: Pass an Array as a function parameter

General Notes:
        hen an array name is passed as a function parameter, the parameter name inside the body of the function
        is no longer a "real array" name, and it has lost all size informattion it had.
        It becomes just a pointer to the first element of the array. 

   [REF]:
   
*/
#include <iostream>
#include <array>

using namespace std;

//

// #define TEST_CASE_1
#ifdef TEST_CASE_1
/*
    Notes:  #define TEST_CASE_1

            Test Case: Array function parameters
*/

// The Array is received as a Pointer parameter, wehere we are not able to know the size of the Array
// double sum(double *scores, size_t count)
double sum(double scores[], size_t count)
{
    double score_sum{};

    // cout << "sizeof(scores): " << sizeof(scores) << endl; // Compiler warning: 'sizeof' on array function parameter 'scores' will return size of 'double*'
    // cout << "sizeof(int*): " << sizeof(int*) << endl; // Same size of the Array Pointer
    // size_t arr_size = size(scores); // Compiler error

    for (size_t i = 0; i < count; ++i)
    {
        score_sum += scores[i];
    }

    return score_sum;
}

int main()
{

    cout << "------------------------------ Test Case 1 -------------------------------------" << endl;

    double my_scores[]{10.0, 12.0, 15.0, 16.0, 17.0};
    cout << "sizeof(my_scores): " << sizeof(my_scores) << endl;
    size_t arr_size = size(my_scores);

    // Passing the name of the array dynamically, will work as passsing by Pointer and it size len
    double result = sum(my_scores, arr_size);

    cout << "result: " << result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_2
#ifdef TEST_CASE_2
/*
    Notes:  #define TEST_CASE_2

            Test Case: Sized array function parameter
*/

// The compiler will ignore the size [5] declaration
double sum(double scores[5], size_t count)
{
    double score_sum{};

    for (size_t i = 0; i < count; ++i)
    {
        score_sum += scores[i];
    }

    return score_sum;
}

int main()
{

    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    // double student_scores[]{10.0, 20.0, 30.0}; // 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 1.0};
    double student_scores[]{10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 1.0};

    double sum_result = sum(student_scores, size(student_scores));

    cout << "result is : " << sum_result << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // Test Case END

//

// #define TEST_CASE_3
#ifdef TEST_CASE_3
/*
    Notes:  #define TEST_CASE_3

            Test Case: Coding Exercise 29: Insert sort - Challenging

            Sorting is one of the common problems in computer science. In this exercise, we will explore
            one of the common sorting algorithms - insertion sort, which is very good when sorting small
            sequences of numbers. 
            Suppose we have an input sequence [6,3,5,7,4,2] and we would like it to be sorted in ascending
            order. With our sorting done right, the output should be [2,3,4,5,6,7].

            Insertion sort works by splitting the input sequence into two sub-sequences : a sorted sub-sequence
            and a unsorted sub-sequence.
*/

void insertion_sort(int *array, unsigned int size)
{
    // We start from index 1 because we consider the element at index 0
    // to be already sorted.
    for (unsigned int i{1}; i < size; ++i)
    {
        int key = array[i];

        int j = i - 1; // We rely on j falling into negative space to stop the while loop.hence the decision to make j signed.
                       // Shift all elements greater than key to the right by one spot.
        while ((j >= 0) && (array[j] > key))
        {
            array[j + 1] = array[j]; // Shift right.
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void print_array(int *arr, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    cout << "------------------------------ Test Case 2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // TEST_CASE_N END

//
