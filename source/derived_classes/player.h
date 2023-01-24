/*

The C++20 Masterclass: Base Class acess specifiers : Public inheritance

General Notes:
        When a class uses public member access specifier to derive from a base, all public
        members of the base class are accessible as public members of the derived class and
        all protected members of the base class are accessible as protected members of the
        derived class (private members of the base are never accessible unless friended).

   [REF]:
    https://en.cppreference.com/w/cpp/language/derived_class
   
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <string_view>
#include "person.h"
#include "person.cpp"

// The Class Player inherites the public and protected members of the Class Person as the Base Class
// Default Case : Derivated Class CAN acess public and protected members of the base Class
// However, the Protected member CANNOT be acessed outside of the Base or Derivated Class

class Player : public Person
{
private:
    string m_game{"None"};
    int m_career_start_year{0};
    double m_salary{0.0};
    int health_factor{0};

public:
    Player() = default;
    Player(string_view game_param);
    Player(string_view game_param, string_view first_name_param,
           string_view last_name_param);

    void play()
    {
        m_full_name = "John Snow"; // OK : Inherited as Public member from Person class where also is a Public member
        m_age = 50;                // OK : Still Protected member in Person class, altough Inherited as Public
        //m_address = "300-293"; // Compiler Error : Still Private member of Person Class
    }

    // A friend function can have a acess in the same way
    friend ostream &operator<<(ostream &out, const Player &player);
    
};

#endif // PLAYER_H