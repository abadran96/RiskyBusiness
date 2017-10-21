//
//  Map.cpp
//  Tester101
//
//  Created by Monique Richard on 2017-10-05.
//  Copyright © 2017 Monique Richard. All rights reserved.
//
#include "Continent.h"
#include "Country.h"
#include "Map.hpp"
#include <iostream>
#include <vector>
Map::Map(){
     numOfContinents=0;
     numOfCountries=0;
}
Map::~Map(){
    
}
//creates continent objects
void Map::createContinent(vector<string> continnames, vector<int> bonus){
    for(int i=0; i < continnames.size(); i++){
        continents.push_back(new Continent(continnames[i] ,i, bonus[i]));
        numOfContinents++;
    }
}

//Have to create Continents first in order for this method to work
void Map::createCountries(vector<string> countrynam, vector<string> continentlist){
    for(int i=0; i < countrynam.size(); i++){
        for(int j=0; j < numOfContinents; j++){
            if(continentlist[i] == continents[j]->get_continent_name()){
                countries.push_back(new Country(countrynam[i], continents[j]));
                continents[j]->addCountryContained(countries[i]);
                numOfCountries++;
                break;
            
            }
                }
   
    }
    
}




void Map::setAdjCountries(vector <vector <string>> adjCount){
    for(int i=0; i < numOfCountries; i++){
        for(int j=0; j< adjCount[i].size();j++){
            
            for(int k=0; k < numOfCountries; k++){
                if(adjCount[i][j]==countries[k]->get_country_name()){
                    countries[i]->addAdjCountry(countries[k]);
                    break;
                }
            }
        }
        
            }
                
            
        }
void Map::PrintAllCountries(){
    for (int i =0; i <numOfCountries; i++){
        cout<< countries[i]->get_country_name() << endl;
        countries[i]->PrintallAdjCountries();
        cout << endl;
    }
}

void Map::validmap(){
    vector<Country*> stack;
    
            vector<Country*> temp = countries[0]->getAdjCountries();
            cout << "Starting Country is: " +countries[0]->get_country_name() <<endl;
            stack.push_back(countries[0]);
            bool visited = false;
            int counter = 0;
    
            //checks if stack is empty
            while(counter<numOfCountries-1){
    
                 visited=false;
    
                while(visited==false){
    
                    //vector of adj_countries
                    for(int i = 0; i < temp.size(); i++){
    
                        visited=false;
                        //vector of stack objects
                        for(int j=0; j < stack.size();j++){
    
                         //was already visited so exit inside loop
                            if (temp[i]==stack[j]){
                                visited=true;
                                break;
                            }
    
                            }
    
                        //if obj in adj vec does not equal stack object, object is added to stack &
                        //temp object is added to stack
                        if(visited==false){
                            stack.push_back(temp[i]);
                            cout << "------------> "<< temp[i]->get_country_name() << endl;
                            temp = temp[i]->getAdjCountries();
                            counter++;
                            visited=true;
                            break;
                        }
                        //pops back if it has been visited & it's the last index of the adjCOuntries
                       if(visited==true&&i==(temp.size()-1)){
                            stack.pop_back();
                            temp = stack[i]->getAdjCountries();
                            break;
                        }
    
    
                    }
    
                       }
    
    
    
               }
    
}


