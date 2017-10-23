#include "MainLoop.h"
#include <iostream>
#include "Player.h"
#include "Country.h"
#include <vector>
#include <stdlib.h>
MainLoop::MainLoop()
{
       //create countries
Country* x1 = new Country("Country1");
Country* x2 = new Country("Country2");
Country* x3 = new Country("Country3");
Country* x4 = new Country("Country4");
Country* x5 = new Country("Country5");
 std::vector <Country*> countries;
    countries.push_back(x1);
    countries.push_back(x2);
    countries.push_back(x3);
    countries.push_back(x4);
    countries.push_back(x5);

    int player_size = 3;//set how many players you want
   std::vector <Player> players;//vector to hold all the players
   for(int i = 1; i < player_size+1; i++) {//fills vector with players
        Player x = Player(i);
        players.push_back(x);
   }

   players[1].addCountry(x1);
   players[2].addCountry(x2);
   players[3].addCountry(x3);
   players[3].addCountry(x4);
   players[3].addCountry(x5);
   players[1].removeCountry(x1);
   players[2].removeCountry(x2);
   players[3].addCountry(x1);
   players[3].addCountry(x2);

bool win = false;

   for(int i = 1; i < player_size+1; i++) {//fills vector with players
       if(players[i].getCountries().size()< 1) {
        cout << "Player" << i << " owns no more countries." << endl;
        player_size= player_size -1;
        cout<<player_size;
       }
   }
   while(win==false){
        if(player_size==1){
            cout<<"A player owns all the countries! Winner!" << endl;
            win= true;
        }
        for(int i=i; i< players.size() ;i++){
      cout << "player " << i <<endl;
      players[i].playerTurn();
       }
}
}

MainLoop::~MainLoop()
{
    //dtor
}

