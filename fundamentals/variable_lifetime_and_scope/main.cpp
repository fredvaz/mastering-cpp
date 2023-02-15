/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>
#include <cstdlib>
#include <cstring>

// #define calculator_v2

#ifdef declaring_and_using_arrays
#include "arrays/declaring_and_using_arrays.h"
#endif

#ifdef size_of_an_array
#include "arrays/size_of_an_array.h"
#endif

#ifdef array_of_characters
#include "arrays/array_of_characters.h"
#endif

#ifdef array_bounds
#include "arrays/array_bounds.h"
#endif

#ifdef generating_random_numbers
#include "arrays/generating_random_numbers.h"
#endif

#ifdef practice_fortune_teller_v1
#include "arrays/practice_fortune_teller_v1.h"
#endif

#ifdef multi_dimensional_arrays
#include "arrays/multi_dimensional_arrays.h"
#endif

#ifdef multi_dimensional_arrays_of_characters
#include "arrays/multi_dimensional_arrays_of_characters.h"
#endif

#ifdef practice_fortune_teller_v2
#include "arrays/practice_fortune_teller_v2.h"
#endif

#ifdef declaring_and_using_references
#include "references/declaring_and_using_references.h"
#endif

#ifdef comparing_pointers_and_references
#include "references/comparing_pointers_and_references.h"
#endif

#ifdef references_and_const
#include "references/references_and_const.h"
#endif

#ifdef references_with_range_based_for_loops
#include "references/references_with_range_based_for_loops.h"
#endif

#ifdef enum_classes
#include "enums_and_type_aliases/enum_classes.h"
#endif

#ifdef using_enum
#include "enums_and_type_aliases/using_enum.h"
#endif

#ifdef old_enums
#include "enums_and_type_aliases/old_enums.h"
#endif

#ifdef type_aliases
#include "enums_and_type_aliases/type_aliases.h"
#endif

// #ifdef grab_and_use_the_arguments
// #include "arguments_to_main_func/grab_and_use_the_arguments.h"
// #endif

#ifdef calculator_v1
#include "arguments_to_main_func/calculator_v1.h"
#endif

// #ifdef calculator_v2
// #include "arguments_to_main_func/calculator_v2.h"
// #endif

// #define Test_main_func

#ifdef overloading_with_different_parameters
#include "function_overloading/overloading_with_different_parameters.h"
#endif

#ifdef overloading_with_pointer_parameters
#include "function_overloading/overloading_with_pointer_parameters.h"
#endif

#ifdef overloading_with_reference_parameters
#include "function_overloading/overloading_with_reference_parameters.h"
#endif

#ifdef overloading_with_const_parameters_by_value
#include "function_overloading/overloading_with_const_parameters_by_value.h"
#endif

#ifdef overloading_with_const_pointer_and_pointer_to_const_parameters
#include "function_overloading/overloading_with_const_pointer_and_pointer_to_const_parameters.h"
#endif

#ifdef overloading_with_const_references
#include "function_overloading/overloading_with_const_references.h"
#endif

#ifdef overloading_with_default_parameters
#include "function_overloading/overloading_with_default_parameters.h"
#endif

#ifdef coding_exercise_34
#include "function_overloading/coding_exercise_34.h"
#endif

#ifdef declaring_and_using_lambdas
#include "lambda_functions/declaring_and_using_lambdas.h"
#endif

#ifdef capture_lists
#include "lambda_functions/capture_lists.h"
#endif

#ifdef capture_all_lists
#include "lambda_functions/capture_all_lists.h"
#endif

#ifdef static_variables
#include "functions_the_misfits/static_variables.h"
#endif

#ifdef inline_functions
#include "functions_the_misfits/inline_functions.h"
#endif

#ifdef recursive_functions
#include "functions_the_misfits/recursive_functions.h"
#endif

#ifdef coding_exercise_35
#include "functions_the_misfits/coding_exercise_35.h"
#endif

#ifdef coding_exercise_36
#include "functions_the_misfits/coding_exercise_36.h"
#endif

//#define coding_exercise_37
#ifdef coding_exercise_37
#include "functions_the_misfits/coding_exercise_37.h"
#endif

//define debugging_in_vscode
#ifdef debugging_in_vscode
#include "function_call_stack_debugging/debugging_in_vscode.h"
#endif

//#define debugging_arrays_loops_and_pointers
#ifdef debugging_arrays_loops_and_pointers
#include "function_call_stack_debugging/debugging_arrays_loops_and_pointers.h"
#endif

//#define destructor
#ifdef destructor
#include "classes/destructor.h"
#endif

//#define destructor_constructor_call_order
#ifdef destructor_constructor_call_order
#include "classes/destructor_constructor_call_order.h"
#endif

//#define this_pointer
#ifdef this_pointer
#include "classes/this_pointer.h"
#endif

//#define struct
#ifdef struct
#include "classes/struct.h"
#endif

//#define size_of_class_objects
#ifdef size_of_class_objects
#include "classes/size_of_class_objects.h"
#endif

//#define friend_functions
#ifdef friend_functions
#include "classes/friend_functions.h"
#endif

//#define friend_classes
#ifdef friend_classes
#include "classes/friend_classes.h"
#endif

//#define creating_namespaces
#ifdef creating_namespaces
#include "namespaces/creating_namespaces.h"
#endif

//#define default_global_namespace
#ifdef default_global_namespace
#include "namespaces/default_global_namespace.h"
#endif

//#define namespaces_across_mutiple_files
#ifdef namespaces_across_mutiple_files
#include "namespaces/namespaces_across_mutiple_files/namespaces_across_mutiple_files.h"
#endif

//#define using_declarations
#ifdef using_declarations
#include "namespaces/using_declarations.h"
#endif

//#define unnamed_namespaces
#ifdef unnamed_namespaces
#include "namespaces/unnamed_namespaces.h"
#endif

//#define nested_namespaces
#ifdef nested_namespaces
#include "namespaces/nested_namespaces.h"
#endif

//#define namespace_aliases
#ifdef namespace_aliases
#include "namespaces/namespace_aliases.h"
#endif

#define inheritance
#ifdef inheritance
#include "derived_classes/inheritance.h"
#endif

using namespace std;

int main(int argc, char **argv)
{
    /*
    General Notes: char **argv <=> char *argv[]
    */
#ifdef Test_main_func
    cout << "\nTest main() func:" << endl;
    
    cout << "We have " << argc << " arguments passed to the program" << endl;

    // Check the number of parameters
    if (argc != 4)
    {
        cerr << "Program can only be called with 3 arguments like: " << endl;
        cerr << "Program name a + b" << endl;
        cerr << "You called with : ";

        for (size_t i{0}; i < argc; i++)
        {
            cout << " " << argv[i];
        }
        cout << endl;
        return 0;
    }
       
    // Grab the operands 
    double first_number{atof(argv[1])};
    double second_number{atof(argv[3])};

    if ((first_number == 0.0) || (second_number == 0.0))
    {
        cout << "Please, use valid numbers (different from zero) for first and second parameter" << endl;
    }

    // Grab the operation
    const char *operation{argv[2]};
    char c;

    if ((strlen(operation) == 1) &&
               ((operation[0] == '+') || 
               (operation[0] == '-') || 
               (operation[0] == 'x') || 
               (operation[0] == '/')))
    {
        c = operation[0];
    }
    else
    {
    cerr << operation << " is not a valid operation." << endl;
    return 0;
    }

    // Do the operation
    switch (c)
    {
    case '+':
        cout << first_number << " + " << second_number << " = "
             << first_number + second_number << endl;
        break;

    case '-':
        cout << first_number << " - " << second_number << "="
             << first_number - second_number << endl;
        break;

    case 'x':
        cout << first_number << " * " << second_number << " = "
             << first_number * second_number << endl;
        break;

    case '/':
        cout << first_number << " / " << second_number << " = "
             << first_number / second_number << endl;
        break;
    }

#endif

#ifdef debugging_in_vscode

    int a{10};
    int b{12};

    int summation = sum(a, b);

    cout << "sum : " << summation << endl;

#endif

#ifdef debugging_arrays_loops_and_pointers

    double numbers[]{10.0, 20.0, 30.0, 40.0, 50.0}; // Sum should be 150.0

    double total = sum(numbers, size(numbers));

    cout << "sum : " << total << endl;

#endif

#ifdef Test1
    cout << "\nTest 1:" << endl;
    test1();
#endif

#ifdef Test2
    cout << "\nTest 2:" << endl;
    test2();
#endif

#ifdef Test3
    cout << "\nTest 3:" << endl;
    test3();
#endif

#ifdef Test4
    cout << "\nTest 4:" << endl;
    test4();
#endif

#ifdef Test5
    cout << "\nTest 5:" << endl;
    test5();
#endif

#ifdef Test6
    cout << "\nTest 6:" << endl;
    test6();
#endif

    cout << endl;
    return 0;
}

#ifdef overloading_with_const_parameters_by_value
int max(const int a, const int b)
{
    //++a; // It wil generate a Compiler error because the var is not allowed to be modified
    return (a > b) ? a : b;
}
#endif

#ifdef overloading_with_default_parameters
void print_age(int age)
{
    cout << "Your age is (int version) : " << age << endl;
}

void print_age(long int age)
{
    cout << "Your age is (long int version) : " << age << endl; 
}
#endif

#ifdef debugging_in_vscode
int &adjust(int & input)
{
    int adjustment{2};
    input += adjustment;
    return input;
}

int sum(int x, int y)
{
    int result = x + y;
    adjust(result);
    return result;
}
#endif