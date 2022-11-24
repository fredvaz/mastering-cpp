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

// #define Test1
// #define functions_first_steps
#ifdef functions_first_steps
#include "functions/functions_first_steps.cpp"
#endif

#define Test1
#define functions_declaration
#ifdef functions_declaration
#include "functions/functions_declaration.cpp"
#endif

// #define Test1
// #define static_variables
#ifdef static_variables
#include "functions/static_variables.h"
#endif

// #define Test1
// #define inline_functions
#ifdef inline_functions
#include "functions/inline_functions.h"
#endif

// #define Test1
// #define recursive_functions
#ifdef recursive_functions
#include "functions/recursive_functions.h"
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

#ifdef with_different_parameters
#include "function_overloading/with_different_parameters.h"
#endif

#ifdef with_pointer_parameters
#include "function_overloading/with_pointer_parameters.h"
#endif

#ifdef with_reference_parameters
#include "function_overloading/with_reference_parameters.h"
#endif

#ifdef with_const_parameters_by_value
#include "function_overloading/with_const_parameters_by_value.h"
#endif

#ifdef with_const_pointer_and_pointer_to_const_parameters
#include "function_overloading/with_const_pointer_and_pointer_to_const_parameters.h"
#endif

#ifdef with_const_references
#include "function_overloading/with_const_references.h"
#endif

#ifdef with_default_parameters
#include "function_overloading/with_default_parameters.h"
#endif

#ifdef coding_exercise_34
#include "function_overloading/coding_exercise_34.h"
#endif

#ifdef declaring_and_using_lambdas
#include "lambda_expressions/declaring_and_using_lambdas.h"
#endif

#ifdef capture_lists
#include "lambda_expressions/capture_lists.h"
#endif

#ifdef capture_all_lists
#include "lambda_expressions/capture_all_lists.h"
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

//#define inheritance
#ifdef inheritance
#include "derived_classes/inheritance.h"
#endif

// #define Test4
// #define constructors_with_inheritance
#ifdef constructors_with_inheritance
#include "derived_classes/constructors_with_inheritance.h"
#endif

// #define Test2
// #define inheriting_base_constructors
#ifdef inheriting_base_constructors
#include "derived_classes/inheriting_base_constructors.h"
#endif

//#define Test1
//#define destructors_and_inheritance
#ifdef destructors_and_inheritance
#include "derived_classes/destructors_and_inheritance.h"
#endif

// #define Test1
// #define reused_symbols_in_inheritance
#ifdef reused_symbols_in_inheritance
#include "derived_classes/reused_symbols_in_inheritance.h"
#endif

// #define Test5
// #define const_objects
#ifdef const_objects
#include "classes_and_objects/const_objects.h"
#endif

// #define Test1
// #define getters_as_setters
#ifdef getters_as_setters
#include "classes_and_objects/getters_as_setters.h"
#endif

// #define Test2
// #define dangling_references_pointers
#ifdef dangling_references_pointers
#include "classes_and_objects/dangling_references_pointers.h"
#endif

// #define Test1
// #define mutable_objects
#ifdef mutable_objects
#include "classes_and_objects/mutable_objects.h"
#endif

// #define Test1
// #define structured_bindings
#ifdef structured_bindings
#include "classes_and_objects/structured_bindings.h"
#endif

using namespace std;

//

// Function Declaration prototypes
// The prototype needs to come before the funcion call in the file
int max(int a, int b); // Function declaration , prototype
                       // Signature doesn't include return type
int min(int a, int b);

int inc_mult(int a, int b);

//

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

#ifdef Test7
    cout << "\nTest 7:" << endl;
    test7();
#endif

    cout << endl;
    return 0;
}

#ifdef functions_declaration
// Function definition or implementation Shows up after main 
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}


//Function definition. Shows up after main 
int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int inc_mult( int a, int b){
    return ( (++a)*(++b));
}
#endif


#ifdef with_const_parameters_by_value
int max(const int a, const int b)
{
    //++a; // It wil generate a Compiler error because the var is not allowed to be modified
    return (a > b) ? a : b;
}
#endif

#ifdef with_default_parameters
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
int &adjust(int &input)
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