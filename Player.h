#ifndef Player_hpp
#define Player_hpp
#include "Dice.hpp"
#include "deck.hpp"
#include "Hand.hpp"
#include "Country.h"


#include <stdio.h>
class Player
{
public:
    Player();
    Player(int);
    std::vector <Country*> getCountries() { return theircountries; }
    int get_player_id();
    void reinforce();
    void attack();
    void fortify();
    
    void playerTurn();
    void addCountry(Country* c);
    int get_number_of_countries() {return number_of_countries; }
    void setDeck(deck* d);
    void setHand(Hand* h);
    void setDice(Dice* d);
    
private:
    int player_id;
    int number_of_countries;
    std::vector <Country*> theircountries;
    Hand* theirhand;
    Dice* theirdice;
    deck* mainDeck;
    
};

#endif /* Player_hpp */
