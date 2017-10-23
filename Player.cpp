#include "Player.hpp"
#include <iostream>
using namespace std;
Player::Player()
{
    player_id = 0;
    theirdice = new Dice();
    theirhand = new Hand();
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
    theircountries.push_back(c);
    number_of_countries ++;
}
void Player::setDeck(deck *d){
    mainDeck = d;
}
void Player::setDice(Dice *d){
    theirdice = d;
}
void Player::setHand(Hand *h){
    theirhand = h;
}
