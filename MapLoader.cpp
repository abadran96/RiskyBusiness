/*
 * MapLoader.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: User
 */

//All the required libraries
#include "MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

bool is_validExt(string fn){
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

bool is_valid(std::string fn) {
    bool value = false;
    int count = 0;
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
int main () {

//This checks if the file extension is the right one.


  string line; //holds the line that we are at in the file

  	  std::vector<string> continents;
  	  std::vector<string> continent2; //This will hold the continents from the file
      std::vector<string> territories; //This will hold the countries from the file
      std::vector<string> x;
      std::vector<string> y;
      std::vector<string> adjacent_territories;


      std::string temp=" ";
      std::string territory=" ";
      std::string continent=" ";
      std::string corx=" ";
      std::string cory=" ";
      std::string adj_terr=" ";
fstream infile;

string filename = "G:\\My Documents\\Comp345\\Part2\\src\\World.map";
bool valid = is_valid(filename);
bool valid2 = is_validExt(filename);
    if(valid == true && valid2 == true){
    infile.open("G:\\My Documents\\Comp345\\Part2\\src\\World.map");
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
    		 continents.push_back(temp);

            }

            for (int i=0; i<continents.size();i++){
            cout << continents[i] << endl;

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
                        getline(str, adj_terr,'\n');

                        adjacent_territories.push_back(adj_terr);
                    }


                if(line==" ") { //if line is empty, skip
                    getline(infile,temp);
                }
    		 territories.push_back(territory);
    		 x.push_back(corx);
    		 y.push_back(cory);
    		 continent2.push_back(continent);

    		 if(infile.eof()) {
                break;
    		 }
    		  }

    		  //printing territories
    		  for (int i=0; i<territories.size();i++){
            cout << territories[i] << "->" << adjacent_territories[i] <<endl;

                }

    		}

    }
   infile.close();
  }




  else cout << "Unable to open file";

  return 0;
}



