//
//  main.cpp
//  Tester101
//
//  Created by Monique Richard on 2017-09-26.
//  Copyright © 2017 Monique Richard. All rights reserved.
//

#include <iostream>
#include "Country.h"
#include "Continent.h"
#include "Map.hpp"
class Map;
#include <vector>

int main() {
//    //Creating map
//    vector<Country*> countries;
//    vector<Continent*> continents;
//    int numOfContinents=0;
//    int numOfCountries=0;
//
//    //vector of Continent names
//    vector<string> con(3);
//
//    con[0]= "America";
//    con[1]= "Africa";
//    con[2]= "Europe";
//
//    //created continents in map
//    for(int i=0; i < con.size(); i++){
//        continents.push_back(new Continent(con[i]));
//        numOfContinents++;
//    }
//
//    //vector of Country names
//    vector<string> count(10);
//    count[0]="Canada";
//    count[1]="USA";
//    count[2]="Greenland";
//    count[3]="Mexico";
//    count[4]="Iceland";
//    count[5]="England";
//    count[6]="Algeria";
//    count[7]="Spain";
//    count[8]="Morocco";
//    count[9]="France";
//
//    //vector of Continent pointers
//    vector<Continent*> continent_of_countries(10);
//    continent_of_countries[0] = continents[0];
//    continent_of_countries[2] = continents[0];
//    continent_of_countries[0] = continents[0];
//    continent_of_countries[1] = continents[0];
//    continent_of_countries[2] = continents[0];
//    continent_of_countries[3] = continents[2];
//    continent_of_countries[4] = continents[2];
//    continent_of_countries[5] = continents[1];
//    continent_of_countries[6] = continents[2];
//    continent_of_countries[7] = continents[2];
//    continent_of_countries[8] = continents[1];
//    continent_of_countries[9] = continents[2];
//
//
//    //Creating countries
//        for(int i=0; i < count.size(); i++){
//            countries.push_back(new Country(count[i], continent_of_countries[i]));
//            continent_of_countries[i]->addCountryContained(countries[i]);
//            numOfCountries++;
//        }
//
//
    //vector of adjCOuntry* vectors
//    vector< vector <Country*>> sample(10);
//
//    sample[0].push_back(countries[1]);
//    sample[0].push_back(countries[2]);
//    sample[1].push_back(countries[0]);
//    sample[1].push_back(countries[3]);
//    sample[2].push_back(countries[0]);
//    sample[2].push_back(countries[4]);
//    sample[3].push_back(countries[1]);
//    sample[4].push_back(countries[2]);
//    sample[4].push_back(countries[5]);
//    sample[5].push_back(countries[4]);
//    sample[5].push_back(countries[9]);
//    sample[6].push_back(countries[7]);
//    sample[6].push_back(countries[8]);
//    sample[7].push_back(countries[6]);
//    sample[7].push_back(countries[9]);
//    sample[8].push_back(countries[7]);
//    sample[8].push_back(countries[6]);
//    sample[9].push_back(countries[7]);
//    sample[9].push_back(countries[5]);
//
//    //assigns adjCountries
//    for(int i=0;i<sample.size();i++){
//       countries[i]->setAdjCOuntries(sample[i]);
//    }
//
//        //this shows that the countries are linked to one Continent which has
//        //a vector with all the countries in it
//        countries[2]->getContinent()->print_allContinentCountries();
//
//
//        //traversing The World
//
//        //array of Countries we have passed
//        vector<Country*> stack;
//
//        vector<Country*> temp = countries[5]->getAdjCountries();
//        cout << "Starting Country is: " +countries[5]->get_country_name() <<endl;
//        stack.push_back(countries[5]);
//        bool visited = false;
//        int counter = 0;
//
//        //checks if stack is empty
//        while(counter<numOfCountries-1){
//
//             visited=false;
//
//            while(visited==false){
//
//                //vector of adj_countries
//                for(int i = 0; i < temp.size(); i++){
//
//                    visited=false;
//                    //vector of stack objects
//                    for(int j=0; j < stack.size();j++){
//
//                     //was already visited so exit inside loop
//                        if (temp[i]==stack[j]){
//                            visited=true;
//                            break;
//                        }
//
//                        }
//
//                    //if obj in adj vec does not equal stack object, object is added to stack &
//                    //temp object is added to stack
//                    if(visited==false){
//                        stack.push_back(temp[i]);
//                        cout << "------------> "<< temp[i]->get_country_name() << endl;
//                        temp = temp[i]->getAdjCountries();
//                        counter++;
//                        visited=true;
//                        break;
//                    }
//                    //pops back if it has been visited & it's the last index of the adjCOuntries
//                    if(visited==true&&i==(temp.size()-1)){
//                        stack.pop_back();
//                        temp = stack[i]->getAdjCountries();
//                        break;
//                    }
//
//
//                }
//
//                    }
//
//
//
//                }
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
    
   m.setAdjCountries(sample);
    m.PrintAllCountries();
    m.validmap();
        }




