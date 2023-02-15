/*

The C++20 Masterclass: Introducing std::optional

General Notes:


   [REF]:
   
*/
#include <iostream>
#include <optional>

using namespace std;

//

// #define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    Notes:  #define EXAMPLE_1

            EXAMPLE: Introducing std::optional
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_1 -------------------------------------" << endl;

    //Declare and initialize
    std::optional<int> items{3};
    std::optional<std::string> name{"Daniel Gakwaya"};
    std::optional<double> weight{77.2};
    std::optional<char> character{'s'};

    //Declare and empty initialize
    std::optional<std::string> dog_name{};     // Initializes to std::nullopt
    std::optional<int> age{std::nullopt};      // std::nullopt is the null or zero equivalent
                                               // for std::optional
    std::optional<char> letter = std::nullopt; // Triggers unused warning
    std::optional<double> height = {};         //Initializes to std::nullopt
                                               // Triggers unused warning.

    //Read from an std::optional variable
    std::cout << "items : " << items.value() << std::endl;
    std::cout << "items : " << *items << std::endl; // Personaly find this confusing as
                                                    // it's not a pointer, so this the
                                                    // first and last time I use it in the
                                                    // course
                                                    //std::cout << "items : " << items << std::endl;
    std::cout << "name : " << name.value() << std::endl;
    std::cout << "weight : " << weight.value() << std::endl;
    std::cout << "character : " << character.value() << std::endl;

    //Write stuff
    dog_name = "Fluffy";
    age = 26;

    std::cout << std::endl;
    std::cout << "Writting data in ..." << std::endl;
    std::cout << "dog_name : " << dog_name.value() << std::endl;
    std::cout << "age : " << age.value() << std::endl;

    //Reading bad data
    //std::cout << letter.value() << std::endl; // Throws exception and crashes program
    //std::cout << height.value() << std::endl; // Trhows exception and crashes program

    //has_value()
    std::cout << std::boolalpha;
    std::cout << "letter.has_value() : " << letter.has_value() << std::endl;
    std::cout << "height.has_value() : " << height.has_value() << std::endl;
    std::cout << "dog_name.has_value() : " << dog_name.has_value() << std::endl;

    //Do your checks before you read data

    std::cout << std::endl;
    std::cout << "Conditional reading" << std::endl;
    if (letter.has_value())
    {
        std::cout << "letter contains a useful value" << std::endl;
    }
    else
    {
        std::cout << "letter contains std::nullopt" << std::endl;
    }

    //Checking against std::nullopt
    if (letter != std::nullopt)
    {
        std::cout << "letter contains a useful value" << std::endl;
    }
    else
    {
        std::cout << "letter contains std::nullopt" << std::endl;
    }

    //Checking against std::nullopt
    if (dog_name != std::nullopt)
    {
        std::cout << "dog_name contains a useful value : " << dog_name.value() << std::endl;
    }
    else
    {
        std::cout << "dog_name contains std::nullopt" << std::endl;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_END

//

// #define EXAMPLE_2
#ifdef EXAMPLE_2
/*
    Notes:  #define EXAMPLE_2

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_2 -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//

// #define EXAMPLE_N
#ifdef EXAMPLE_N
/*
    Notes:  #define EXAMPLE_N

            EXAMPLE: 
*/

//

int main()
{
    cout << "------------------------------ EXAMPLE_N -------------------------------------" << endl;

    //

    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}

#endif // EXAMPLE_N END

//