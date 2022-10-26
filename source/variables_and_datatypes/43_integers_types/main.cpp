/*

The C++20 Masterclass: From Fundamentals to Advanced

*/

#include <iostream>


int main(){
    
    // Braced initializers
    std::cout << "-------- Braced initializers --------" << std::endl; 
    
    int elephant_count; // Variable may contain random garbage value . WARNING because is not initialized
    int lion_count{};   // Initializes to zero
    int dog_count {10}; // Initializes to 10
    int cat_count {15}; // Initializes to 15
    int domesticated_animals { dog_count + cat_count };  // Can use expression as initializer
    //int new_number{doesnt_exist};
    //int narrowing_conversion {2.9}; // Compiler error "2.9" is a float

    std::cout << "Elephant count: " << elephant_count << std::endl;
    std::cout << "Lion count: " << lion_count << std::endl;
    std::cout << "Dog count: " << dog_count << std::endl;
    std::cout << "Cat count: " << cat_count << std::endl;
    std::cout << "Domesticated animal count : " << domesticated_animals << std::endl;


    // Functional Initialization
    std::cout << "-------- Functional Initialization --------" << std::endl; 

    int apple_count(5);
    int orange_count(10);
    int fruit_count (apple_count + orange_count);
    //int bad_initialization ( doesnt_exist3 + doesnt_exist4 );
    int narrowing_conversion_functional (2.9);  // Implicit Converstion. Information lost. less safe than braced initializers. Because is declared as int onlly the interger part will be stored
        
    std::cout << "Apple count : " << apple_count << std::endl;
    std::cout << "Orange count : " << orange_count << std::endl;
    std::cout << "Fruit count : " << fruit_count << std::endl;
    std::cout << "Narrowing conversion : " << narrowing_conversion_functional << std::endl;//Will loose info


    //Assignment notation
    std::cout << "-------- Assignment notation --------" << std::endl;

    int bike_count = 2;
    int truck_count = 7;
    int vehicle_count = bike_count + truck_count;
    int narrowing_conversion_assignment = 2.9;

    std::cout << "Bike count : " << bike_count << std::endl;
    std::cout << "Truck count : " << truck_count << std::endl;
    std::cout << "Vehicle count : " << vehicle_count << std::endl;
    std::cout << "Narrowing conversion : " << narrowing_conversion_assignment << std::endl;
    

    // Check the size with sizeof
    std::cout << "sizeof int : " << sizeof(int) << std::endl;
    std::cout << "sizeof truck_count : " << sizeof(truck_count) << std::endl;


    return 0;
}