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


//main function
int main () {


	//This checks if the file extension is the right one.

	std::string fn = "";
	  if(fn.substr(fn.find_last_of(".") + 1) == "txt" //checks that it ends with .txt
			  || fn.substr(fn.find_last_of(".") + 1) == "map" ) { //checks that it ends with .map
	    std::cout << "Yes... This a valid file extension" << std::endl;
	  } else {
	    std::cout << "This is not a valid file extension" << std::endl;
	  }

  string line;
  ifstream myfile ("example.txt");

  	  std::vector<string> continents; //This will hold the continents from the file
      	string c = 0;
      std::vector<string> countries; //This will hold the countries from the file
      string d = 0;

  if (myfile.is_open())
  {
	  getline(myfile, line);
	  if(line!="[Map]")
		  cout<<"This is not a valid MAP file";

    while ( getline (myfile,line) ) //while there are still lines in the file
    {
    	if(line == "[Continents]"){ //check if one of them is the start of the continents
    		 cout << "Here are the continents in the map: " << endl;
    		while (line!="Territories]"){ //Makes sure we don't go past the Territories point
    		getline(myfile, c);//Goes through the next lines
        	continents.push_back(c); //Adds the continent to the vector of strings called continents
        	 cout << c << endl; //Prints the list of continents as they are added
    		}

    	}

    	else if(line == "[Territories]") {
    		cout << "Here are the territories: " << endl;
    		while(getline(myfile,d)) {

    		}
    	}
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return 0;
}
