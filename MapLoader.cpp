//
//  MapLoader.cpp
//  Tester101
//
//  Created by Monique Richard on 2017-10-21.
//  Copyright © 2017 Monique Richard. All rights reserved.
//

#include "MapLoader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
MapLoader::MapLoader(){
    
}
MapLoader::~MapLoader(){
    
}

bool MapLoader::is_validExt(string fn){
    //This checks if the file extension is the right one.
    
    if(fn.substr(fn.find_last_of(".") + 1) == "txt" //checks that it ends with .txt
       || fn.substr(fn.find_last_of(".") + 1) == "map" ) { //checks that it ends with .map
        std::cout << "Yes... This a valid file extension" << std::endl;
        return true;
        
    } else {
        std::cout << "This is not a valid file extension" << std::endl;
        return false; //terminate
    }
}

bool MapLoader::is_valid(string fn) {
    bool value = false;
    string line = "" ;
    ifstream infile;
    infile.open(fn.c_str());
    if (!infile.eof())
    {
        while (!infile.eof()){
            getline(infile, line);
            if(line=="[Map]"){
                cout<<"This has MAP component";
            }
            if(line=="[Continents]"){
                cout<<"This has CONTINENTS component";
            }
            if(line=="[Territories]"){
                cout<<"This has TERRITORIES component";
                value = true;
            }
        }
        if (!value == true){
            cout<<"This is not a valid MAP file!";
            value=false;
        }
        
    }
    infile.close();
    
    return value;
}

//main function
int MapLoader::createMap(string fn){
    
    //This checks if the file extension is the right one.
    
    
    string line; //holds the line that we are at in the file
    
    //std::vector<string> continents;
    //std::vector<string> continent2; //This will hold the continents from the file
    //std::vector<string> territories; //This will hold the countries from the file
    std::vector<string> x;
    std::vector<string> y;
    std::vector<string> adjacent_territories; // temp for the real adj_territories
    
    
    std::string temp=" ";
    std::string territory=" ";
    std::string continent=" ";
    std::string corx=" ";
    std::string cory=" ";
    std::string adj_terr=" ";
    fstream infile;
    
    string filename = fn;
    bool valid = is_valid(fn);
    bool valid2 = is_validExt(fn);
    if(valid2 == true&& valid==true){
        infile.open(fn);
    }
    else{
        return 0;
    }
    
    
    if (infile.is_open())
    {
        
        
        while(!infile.eof())  //while the file isn't empty
        {
            getline (infile,line);
            if(line == "[Continents]"){ //check if one of them is the start of the continents
                cout << "Here are the continents in the map: " << endl;
                
                while(line!="[Territories]"){ //keeps going until territory line
                    getline(infile,line);
                    stringstream str(line);
                    getline(str,temp,'=');
                    
                    if(line == "") { //if line is empty, skip
                        getline(infile,line);
                    }
                    if(line == "[Territories]") {
                        break;
                    }
                    continentnames.push_back(temp);
                    
                }
                
                for (int i=0; i<continentnames.size();i++){
                    cout << continentnames[i] << endl;
                    
                }
                //end of continents
                
                
            }if(line == "[Territories]") {
                if(line=="[Territories]") { //if line is empty, skip
                    getline(infile,line);
                }
                cout << "Here are the territories: " << endl;
                while (!infile.eof()){
                    getline(infile,line);
                    stringstream str(line);
                    getline(str,territory,',');
                    getline(str,corx,',');
                    getline(str,cory,',');
                    getline(str,continent,',');
                    while(str.good()){
                        getline(str, adj_terr,',');//change to get a vector vector of strings
                        adjacent_territories.push_back(adj_terr);
                    }
                      adj_countries.push_back(adjacent_territories);
                    
                    if(line==" ") { //if line is empty, skip
                        getline(infile,temp);
                    }
                    countries.push_back(territory);
                    x.push_back(corx);
                    y.push_back(cory);
                    continentlist.push_back(continent);
                    
                    if(infile.eof()) {
                        break;
                    }
                }
                
                //printing territories
                for (int i=0; i<countries.size();i++){
                    cout << countries[i] << "->" << adjacent_territories[i] <<endl;
                    
                }
                
            }
            
        }
        infile.close();
    }
    
    
    
    
    else cout << "Unable to open file";
    
    return 0;
}



