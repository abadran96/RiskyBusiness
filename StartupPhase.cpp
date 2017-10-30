#include "StartupPhase.h"
#include "Player.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Map.h"
#include "Country.h"


using namespace std;

auto rng = std::default_random_engine {};


//Constructor
StartupPhase::StartupPhase()
{
    cout << "This is the startup phase!"<< endl;
    cout << "Please enter the number of players you'd like to have (2-6)"<< endl;
    cin >> number_of_players;
    cout << number_of_players << " players will be created" << endl;
    setNumberOfPlayers(number_of_players);
    createPlayers();
    randomCountries();
    assignCountries();
    assignCountryArmies();
}

//Method to set the number of players that will be created
void StartupPhase::setNumberOfPlayers(int p)
{
    number_of_players = p;
}

//This method will take in the numbers of players the user would like thave
//and shuffle the order so that it is randomized
vector <Player> StartupPhase::createPlayers()
{
    //Loop to create the players and store them in a vector
    for(int i = 1; i < getNumberOfPlayers()+1; i++)  //fills vector with players
    {
        Player x = Player(i);
        players.push_back(x);
    }

    //random generator
    std::shuffle ( players.begin(), players.end(), rng );

    //Need to randomize better because it stays the same
    //Printing the new order of the players
    cout<<"The new order of plays is:" << endl;
    for(int i=0; i < players.size() ; i++)
    {
        cout << "Player: " << players[i].get_player_id() << endl;
    }

    std::cout << '\n';

    //set armies for players
    //Assign armies based on game rules depending on how many players are created
    for(int i=0; i < players.size() ; i++)
    {

        //switch statements to be executed depending on the number of players
        switch(players.size())
        {
        case 2:
            players[i].set_playerArmies(40);
            break;
        case 3:
            players[i].set_playerArmies(35);
            break;
        case 4:
            players[i].set_playerArmies(30);
            break;
        case 5:
            players[i].set_playerArmies(25);
            break;
        case 6:
            players[i].set_playerArmies(20);
            break;
        default:
            cout<< "Not a valid player size" << endl;
            break;
        }

        //print players armies
        cout << "Player: " << players[i].get_player_id() << " armies: " << players[i].get_playerArmies() << endl;
    }
    return players;
}



//randomize the countries

vector <Country*> StartupPhase:: randomCountries()
{

    //Creates the map and assigns the countries to the countries vector
    Map m;
    vector<string> continnames;
    vector<int> bonus;
    vector<string> countrynam;
    vector<string> continentlist;
    //vector of Country names
    vector<string> count(10);
    count[0]="Canada";
    count[1]="USA";
    count[2]="Greenland";
    count[3]="Mexico";
    count[4]="Iceland";
    count[5]="England";
    count[6]="Algeria";
    count[7]="Spain";
    count[8]="Morocco";
    count[9]="France";
    continentlist.push_back("America");
    continentlist.push_back("America");
    continentlist.push_back("America");
    continentlist.push_back("America");
    continentlist.push_back("Europe");
    continentlist.push_back("Europe");
    continentlist.push_back("Africa");
    continentlist.push_back("Europe");
    continentlist.push_back("Africa");
    continentlist.push_back("Europe");

    continnames.push_back("America");
    continnames.push_back("Africa");
    continnames.push_back("Europe");
    bonus.push_back(5);
    bonus.push_back(6);
    bonus.push_back(7);
    m.createContinent(continnames, bonus);
    m.createCountries(count,  continentlist);

    vector< vector <string>> sample(10);
    sample[0].push_back("USA");
    sample[0].push_back("Greenland");
    sample[1].push_back("Canada");
    sample[1].push_back("Mexico");
    sample[2].push_back("Canada");
    sample[2].push_back("Iceland");
    sample[3].push_back("USA");
    sample[4].push_back("Greenland");
    sample[4].push_back("England");
    sample[5].push_back("Iceland");
    sample[5].push_back("France");
    sample[6].push_back("Spain");
    sample[6].push_back("Morocco");
    sample[7].push_back("Algeria");
    sample[7].push_back("France");
    sample[8].push_back("Spain");
    sample[8].push_back("Algeria");
    sample[9].push_back("Spain");
    sample[9].push_back("England");

    //m.setAdjCountries(sample);
    //m.PrintAllCountries();


    cout << "The size of countries: " <<m.getCountries().size() <<endl;

    shuffledCountries = m.getCountries();
    //randomizer

    std:: shuffle ( shuffledCountries.begin(), shuffledCountries.end(), rng );

    //Need to randomize better because it stays the same
    cout<<"The new order of countries is:" << endl;

    for(int i=0; i < shuffledCountries.size() ; i++)
    {
        cout << "Country: " <<  shuffledCountries[i]->get_country_name()<< endl;
    }

    std::cout << '\n';
    return shuffledCountries;
}

void StartupPhase:: assignCountries()
{
    cout<<"number of countries: " << shuffledCountries.size()<< endl;
    cout<<"Number of players: " << players.size() << endl;

    for(int i = 0; i < shuffledCountries.size();)
    {

        for(int j = 0; j < players.size(); j++)
        {
            cout<< shuffledCountries[i]->get_country_name() << " ";
            players[j].addCountry(shuffledCountries[i]);


            i++;

            if(shuffledCountries[shuffledCountries.size()] == shuffledCountries[i])
            {
                break;
            }
        }

    }
}

void StartupPhase:: assignCountryArmies()
{
    cout<<"Assigning armies now!" << endl;
    for(int i = 0; i < players.size();) //for every player
    {
        cout << "Player "  << players[i].get_player_id() << " is having its armies distributed." << endl;
        cout<< "Player " << players[i].get_player_id() << " armies: " << players[i].get_playerArmies()<< endl;


        // keep going until that player doesn't have anymore armies
        while((players[i].get_playerArmies()) > 0)
        {
            for(int j = 0; j < players[i].getpCountries().size(); j++)  //for every country in i
            {
                // add one army to that country
                players[i].getpCountries()[j]->increment_armies();
                players[i].decrement_armies(); //remove that army from the player

                if(players[i].get_playerArmies()< 1)
                {
                    break;
                }
            }
            cout<< "Player " << players[i].get_player_id() << " armies: " << players[i].get_playerArmies()<< endl;

        }
        i++;
    }

    for(int i = 0; i < shuffledCountries.size(); i++)
    {
        cout<< shuffledCountries[i]->get_country_name() << " has ";
        cout<< shuffledCountries[i]->get_armies() << " armies"<<endl;
    }

}








StartupPhase::~StartupPhase()
{
    //dtor
}
