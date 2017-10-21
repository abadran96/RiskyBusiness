#include "hand.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "deck.h"

using namespace std;

hand::hand()
{
    //ctor
}

void hand::createHand(int x)
{

    deck deckO;
    deckO.setDeck(x);
    cout<<deckO.getDeck()<<endl;
//    int numberOfCards= getDeck();
    cout<<"Input -1 to end program early - press any button to continue:"<<endl;

    srand(time(0));//changes up the random numbers

    vector<char> hand;
    int userChoice=0;//variable stop the while loop if = -1
    int noChoice=0;//counter for number of times ran
    cin>>userChoice;

    while(userChoice!=-1)
        {

            int randCounter=1;




            int randIndex=rand()%deckO.getDeck();//first random gen
            cout<<endl;
            cout<< randCounter<< "st random chosen for this attempt is "<<randIndex <<"\nThe " <<decko[randIndex]<<" card was picked"<<endl;

            while(deck[randIndex]=='d')//'d' == drawn
            {
                randCounter++;
                randIndex=rand()%deckO.getDeck();
                cout<<randCounter<<"nd random chosen for this attempt is "<<randIndex<<"\t - The " <<decko[randIndex]<<" card was picked"<<endl;
            }


            handVector.push_back(deck[randIndex]);
            deck[randIndex]='d';
            noChoice++;


            cout<<"Input -1 to end program early - press any button to continue:"<<endl;
            cout<<endl;
            cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
            cin>>userChoice;



            if(noChoice==5)
                userChoice=-1;


        }

        cout<<"Drew "<<noChoice<<" times!"<<endl;

        for(int i=0; i<handVector.size();i++)
        {
            cout<<handVector[i]<<" ";
        }


}
