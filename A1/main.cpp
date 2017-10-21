//Group 1
//COMP 345
//Fall 2k17


#include "deck.h"
#include "hand.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


//using namespace std;

const int noCards=20;


int main()
{

deck deckObj;
deckObj.setDeck(1000);
int snapple=deckObj.getDeck();
cout << snapple<<endl;
deckObj.createDeck();


std::cout<<"/////////////////////////////////////////////////////////////////"<<std::endl;

//    vector<char> deck;//define vector deck of type char
//    vector<int> share(3);//define vector share of type int and with 3 null index places
//    int noCards=20;
//
//
//
//    for(int i=0; i<noCards; i++)//loops through vector deck
//    {
//        //'I' is infantry type
//        //'C' is cavalry type
//        //'A' is artillery type
//        switch(i%3)//change consecutive index into I,C,A pattern
//        {
//            //evenly distribute number of card types
//            case 0:
//                deck.push_back('I');
//                break;
//            case 1:
//                deck.push_back('C');
//                break;
//            case 2:
//                deck.push_back('A');
//                break;
//
//        }
//
//
//    }
//    cout<<"Evenly distributed vector: ";
//    for(int i=0;i<noCards;i++)
//        cout << deck[i] << " ";
//
//    cout<<endl;
//
//    cout<<"Size of deck vector: "<<deck.size()<<"\nSize of share vector: "<<share.size()<<endl;
//
//
//    for(int i=0;i<noCards;i++){//loops length of deck
//
//        switch(deck[i])
//        {
//            case 'I'://increments share vector for every identical pattern
//                ++share[0];
//                break;
//            case 'C':
//                ++share[1];
//                break;
//            case 'A':
//                ++share[2];
//                break;
//
//
//        }
//
//
//    }
//
//    for(int i=0;i!=share.size();i++)
//    {
//        cout<<(i+1)<<"th type's freq: "<<share[i]<<"/"<< noCards<<endl;
//
//    }
//

//
//
//    cout<<"-----------------------------------------------------------------------"<<endl;
    //DRAW() method
//
//    cout<<"Input -1 to end program early - press any button to continue:"<<endl;
//
//    srand(time(0));//changes up the random numbers
//
//    vector<char> hand;
//    int userChoice=0;//variable stop the while loop if = -1
//    int noChoice=0;//counter for number of times ran
//    cin>>userChoice;
//
//    while(userChoice!=-1)
//        {
//
//            int randCounter=1;
//
//
//
//
//            int randIndex=rand()%noCards;//first random gen
//            cout<<endl;
//            cout<< randCounter<< "st random chosen for this attempt is "<<randIndex <<"\nThe " <<deck[randIndex]<<" card was picked"<<endl;
//
//            while(deck[randIndex]=='d')//'d' == drawn
//            {
//                randCounter++;
//                randIndex=rand()%noCards;
//                cout<<randCounter<<"nd random chosen for this attempt is "<<randIndex<<"\t - The " <<deck[randIndex]<<" card was picked"<<endl;
//            }
//
//
//            hand.push_back(deck[randIndex]);
//            deck[randIndex]='d';
//            noChoice++;
//
//
//            cout<<"Input -1 to end program early - press any button to continue:"<<endl;
//            cout<<endl;
//            cout<<"//////////////////////////////////////////////////////////////////////"<<endl;
//            cin>>userChoice;
//
//
////
//            if(noChoice==5)
//                userChoice=-1;
//
//
//        }
//
//        cout<<"Drew "<<noChoice<<" times!"<<endl;
//
//        for(int i=0; i<hand.size();i++)
//        {
//            cout<<hand[i]<<" ";
//        }
//
//




}
