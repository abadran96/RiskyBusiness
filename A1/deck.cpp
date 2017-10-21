#include "deck.h"

#include <vector>
#include <iostream>
using namespace std;



deck::deck()
{
    vector<char> decko;
    vector<int> share(3);
    int noCards=0;
}



void deck::setDeck(int nC)
{
    noCards=nC;
}

int deck::getDeck()
{
    return noCards;
}


void deck::createDeck(){



    vector<char> decko;//define vector deck of type char
    vector<int> share(3);//define vector share of type int and with 3 null index places




    for(int i=0; i<noCards; i++)//loops through vector deck
    {
        //'I' is infantry type
        //'C' is cavalry type
        //'A' is artillery type
        switch(i%3)//change consecutive index into I,C,A pattern
        {
            //evenly distribute number of card types
            case 0:
                decko.push_back('I');
                break;
            case 1:
                decko.push_back('C');
                break;
            case 2:
                decko.push_back('A');
                break;

        }


    }
    cout<<"Evenly distributed vector: ";
    for(int i=0;i<noCards;i++)
        cout << decko[i] << " ";

    cout<<endl;

    cout<<"Size of deck vector: "<<decko.size()<<"\nSize of share vector: "<<share.size()<<endl;


    for(int i=0;i<noCards;i++){//loops length of deck

        switch(decko[i])
        {
            case 'I'://increments share vector for every identical pattern
                ++share[0];
                break;
            case 'C':
                ++share[1];
                break;
            case 'A':
                ++share[2];
                break;


        }


    }

    for(int i=0;i!=share.size();i++)
    {
        cout<<(i+1)<<"th type's freq: "<<share[i]<<"/"<< noCards<<endl;

    }

}
