#include "deck.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;



deck::deck()
{
    noCards=0;
}

void deck::setCardNo(int nO)//will set amount of cards
{
    noCards=nO;
}

int deck::getCardNo()//return amount of cards
{
    return noCards;
}

char deck::createDeck(int amount)//will create vector deck
{
    setCardNo(amount);//numb cards
    getCardNo();//return cards
    vector<int> share(3);//vector that will keep count of frequency of cards


    for(int i=0;i<getCardNo();i++)
    {
        switch(i%3)//3 consecutive numbers will be changed in a I,C,A pattern
        {
        case 0:
            theDeck.push_back('I');

            break;
        case 1:
            theDeck.push_back('C');
            break;
        case 2:
            theDeck.push_back('A');
            break;

        }

    }

    for(int i=0; i<theDeck.size();i++){//prints out the content of vector theDeck
        cout << theDeck[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"Size of deck vector: "<<theDeck.size()<<endl;


    for(int i=0;i<noCards;i++)
    {//will print the composition of deck withing 3 index places

        switch(theDeck[i])
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

    for(int i=0;i!=share.size();i++)//prints proof of fair game
    {
        cout<<(i+1)<<"th type's freq: "<<share[i]<<"/"<< noCards<<endl;

    }

}




void deck::Draw(){

//generate random number


//use while loop to check if its = i c a



// if it not i c a then re-pick with rand number till not taken




    cout<<"-----------------------------------------------------------------------"<<endl;




    srand(time(0));//changes random numbers constantly


    vector<char> hand;//vector hand
    vector<int> check(3);//shows status of hand compostion
    int numberExchanges=1;//number of times exchange() has been called ++ each time
    int counterDraws=5;



        for(int i=0; i<counterDraws;i++)
        {

            int randCounter=1;




            int randIndex=rand()%noCards;//first random gen
            cout<<endl;


            if(theDeck[randIndex]!='d')
                cout<< randCounter<< "st random index chosen for this attempt is "<<randIndex <<"\nThe " <<theDeck[randIndex]<<" card was picked"<<endl;





            while(theDeck[randIndex]=='d')//will draw a new random number index until it finds one not marked as 'd'
            {
                randCounter++;
                randIndex=rand()%noCards;
                    if(theDeck[randIndex]!='d')
                        cout<<randCounter<<"nd random index chosen for this attempt is "<<randIndex<<"\nThe " <<theDeck[randIndex]<<" card was picked"<<endl;




            }


            hand.push_back(theDeck[randIndex]);//adds the non 'd' value to the vector hand
            theDeck[randIndex]='d';//marks the index we took from deck as 'd', no longer will be picked





cout<<"============================================="<<endl;



            switch(hand[i])//prints status of card inventory
                {
                case 'I':
                    ++check[0];
                    break;
                case 'C':
                    ++check[1];
                    break;
                case 'A':
                    ++check[2];
                    break;

                }


                cout<<"I: "<<check[0]<<" ";
                cout<<"C: "<<check[1]<<" ";
                cout<<"A: "<<check[2]<<endl;





            if(check[0]>=1 && check[1]>=1 && check[2]>=1)//will tell us if you have enough cards to exchange, if so will give option to trade them in for armies
            {
                string agree;
                cout<<endl;
                cout<<"3 all different - you may exchange them for armies"<<endl;//trades your cards and then returns to draw and picks two remaining cards
                cout<<"To begin exchange input 'y'"<<endl;
                cin>>agree;
                 if(agree=="y"||agree=="Y")
                    {
                    cout<<"You get "<<exchange(numberExchanges)<<" armies in return for your 3 different cards"<<endl;
                    numberExchanges++;
                    check[0]=check[0]-1;
                    check[1]=check[1]-1;
                    check[2]=check[2]-1;

                    }

            }



             if(check[0]==3 || check[1]==3 || check[2]==3)//identical but in triggered if 3 cards are the same
             {
                string agree;
                cout<<endl;
                cout<<"3 of a kind - you may exchange them for armies"<<endl;
                cout<<"To begin exchange input 'y'"<<endl;
                cin>>agree;
                 if(agree=="y"||agree=="Y")
                    {
                     cout<<"You get "<<exchange(numberExchanges)<<" armies in return for your 3 same cards"<<endl;
                     numberExchanges++;
                     for(int i=0;i<check.size();i++)
                     {
                         if(check[i]==3)
                            check[i]=0;
                     }




                    }

             }






        }

        cout<<endl;
        cout<<"here are the cards you drew: ";
        for(int i=0; i<hand.size();i++)
        {
            cout<<hand[i]<<" ";
        }




        cout<<"\n-------------------------------------------------------------------------"<<endl;




}

int deck::exchange(int n)
{

    return 5*n;

}






