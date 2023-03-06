/*

The C++20 Masterclass Section 42: Exception Handling

General Notes:
    Exception handling provides a way of transferring control and information from some point in the execution
    of a program to a handler associated with a point previously passed by the execution (in other words,
    exception handling transfers control up the call stack)

   [REF]:
    https://en.cppreference.com/w/cpp/language/exceptions
    https://cplusplus.com/doc/tutorial/exceptions/

*/
#include <iostream>

//

class Animal
{
public:
    Animal() = default;
    virtual void breathe() const {};

private:
    std::string m_description;
};

class Dog : public Animal
{
public:
    Dog() = default;
    virtual void breathe() const override{};
    void run()
    {
        std::cout << "Dog running..." << std::endl;
    }

private:
    std::string m_fur_color;
};

 //*  Function throws const char* exception when par_b is zero
 void process_parameters( int par_a , int par_b){
     
     // Do some processing 
     if(par_b == 0)
         throw "Potential division by 0 detected";
     
     int result = par_a / par_b;
     
     //Some other processing.
 }

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

            * EXAMPLE: The need for exceptions
            * e.g.:
            * - int division by 0
            * - Downcast using no compatible dynamic cast with referentes
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //! int division by 0: CRASH

    const int a{45};
    const int b{0};
    int result = a / b;
    std::cout << "Done!" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //! Downcast using dynamic_cast with references
    //! The hierarchy of Animal->Dog has to be polymorphic to be able to do
    //! this. This throws an exception because animal has no dog part so the
    //! cast won't really work.

    Animal a;
    Dog &d{dynamic_cast<Dog &>(a)};

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

#define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    !Note:  #define EXAMPLE_2

            * EXAMPLE: The need for exceptions (Implementation)
*/

int main()
{
    std::cout << "------------------------------ EXAMPLE_2 -------------------------------------" << std::endl;

    //* Exceptions allow us to recover from these errors and give
    //* our program a chance to continue running.

    //* Integer division

    const int a{45};
    const int b{0};
    int result;

    try
    {
        if (b == 0)
            throw 0;
        result = a / b;
    }
    catch (std::string ex)
    {
        // Some processing
        std::cout << "Something went wrong: " << ex << std::endl;
    }
    catch (int ex) //* Mutiple catch
    {
        std::cout << "Integer division detected, ex: " << ex << std::endl;
    }
    
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    //* Exceptions thrown out of other parts of code written by you
    //* or somebody else
    try
    {
        process_parameters(10, 0);
    }
    catch (const char *ex) //* In this case receives a throw exception commign from the function above
    {
        std::cout << "Exception: " << ex << std::endl;
    }
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_2 END

//
