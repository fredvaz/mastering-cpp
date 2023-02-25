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
#include "person.h"
#include "player.h"

using namespace std;

Player::Player(string_view game_param)
    : m_game(game_param)
{
    m_game = game_param;
#ifdef Test1
    // Compiler error : Player Class cannot acess the private members of Class Person
    //first_name = "John";
    //last_name = "Snow";
#endif
    // Protected members : Only Player Class can acess the private members of Class Person
#ifdef Test2
    //first_name = first_name_param;
    //last_name = last_name_param;
    first_name = "John";
    last_name = "Snow";
#endif
}

#ifdef Test2
Player::Player(string_view game_param, string_view first_name_param,
               string_view last_name_param)
{
    m_game = game_param;
    first_name = first_name_param;
    last_name = last_name_param;
}
#endif

#ifndef Test3
ostream &operator<<(ostream &out, const Player &player)
{
    out << "Player : [ game : " << player.m_game
        << " names : " << player.get_first_name()
        << " " << player.get_last_name() << "]";

    return out;
}
#endif

#ifdef Test3
ostream &operator<<(ostream &out, const Player &player)
{
    out << "Player[Full name : " << player.m_full_name 
        << ",age : " << player.m_age
        << ",address : " << player.get_address() 
        << "]";

    return out;
}
#endif