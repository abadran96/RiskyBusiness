#include "Player.h"
#include <iostream>
using namespace std;
Player::Player()
{
	player_id = 0;
	//std::cout << get_player_id() + " Player object created." << std::endl;

}


Player::Player(int id) {
    using namespace std;
	cout <<" Player " << id << " created." << endl;
	player_id = id;
	number_of_countries = 0;

}

   void Player::reinforce() {
    cout<<"You are in the reinforcing stage."<<endl;
    }

     void Player:: attack() {
    cout<<"You are in the attack stage."<<endl;
    }

     void Player:: fortify() {
    cout<<"You are in the fortifying stage."<<endl;
    }

   void Player::playerTurn() {
    reinforce();
    attack();
    fortify();
    }

int Player::get_player_id() {
	return player_id;
}


    void Player::addCountry(Country* c){
    countries.push_back(c);
}


void Player::removeCountry(Country* country) {
	//An arbitrary value to be used to indicate whether the country was found in the player's countries_owned vector.
	int index = -1;
	int countries_owned = countries.size();
	for(int i=0; i<countries_owned; i++) {
		if(countries.at(i) == country) {
			index = i;
		}
	}
		if(index == -1) {
		std::cout << "You do not own that country" << std::endl;
	}
	//remove country
	else {
		countries.erase(countries.begin()+index);
		std::cout << "Country was erased." << std::endl;

	}
}


//Country* Player::get_country(int index) {
	//return countries_owned.at(index);


