#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Map.h"


using namespace std;

class Player
{
public:

    Player();
	Player(int);


   std::vector <Country*> getCountries() { return countries; }
	int get_player_id();


   //   Dice:: Dice();

      void reinforce();
      void attack();
      void fortify();

      void playerTurn();
      void addCountry(Country* c);
      int get_number_of_countries() {return number_of_countries; }

    private:
    int player_id;
    int number_of_countries;
    std::vector <Country*> countries;
    //std::vector<Continent*> continents;
    // std::vector<Deck> hand;

};

#endif // PLAYER_H
