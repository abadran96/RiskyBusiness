//
//  Hand.cpp
//  Tester101
//
//  Created by Monique Richard on 2017-10-21.
//  Copyright © 2017 Monique Richard. All rights reserved.
//

#include "Hand.hpp"
#include "deck.hpp"
class deck;
#include <vector>
#include <iostream>
using namespace std;
Hand::Hand(){
    numOfCards=0;
    D = new deck();
}

Hand::Hand(std::vector<char> cars){
    numOfCards = cars.size();
    cards = cars;
}
Hand::~Hand(){
    
}

void Hand::exchange(){
    
    int check[3];
    for(int i=0;i<3;i++){
    switch(cards[i])//prints status of card inventory
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
    
    
    cout <<"I: "<<check[0]<<" ";
    cout <<"C: "<<check[1]<<" ";
    cout <<"A: "<<check[2]<< endl;
        
    }
    vector<char>::iterator it;
    if(check[0]>=1 && check[1]>=1 && check[2]>=1)//will tell us if you have enough cards to exchange, if so will give option to trade them in for armies
    {
        string agree;
        cout<<endl;
        cout<<"3 all different - you may exchange them for armies"<<endl;//trades your cards and then returns to draw and picks two remaining cards
        cout<<"To begin exchange input 'y'"<<endl;
        cin>>agree;
        if(agree=="y"||agree=="Y")
        {
            cout<<"You get "<<rateOfExchange()<<" armies in return for your 3 different cards"<<endl;
            D->incrementSetsReturned();
            check[0]=check[0]-1;
            check[1]=check[1]-1;
            check[2]=check[2]-1;
            cards.erase(remove(cards.begin(),cards.end(),'I'),cards.end());
         
            cards.erase(remove(cards.begin(),cards.end(),'C'),cards.end());
         
           cards.erase(remove(cards.begin(),cards.end(),'A'),cards.end());
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
            cout<<"You get "<<rateOfExchange()<<" armies in return for your 3 same cards"<<endl;
            D->incrementSetsReturned();
            if(check[0]==3){
                for(int j =0;j<3;j++){
                    cards.erase(remove(cards.begin(),cards.end(),'I'),cards.end());
                }
            }
            if(check[1]==3){
                for(int j =0;j<3;j++){
                    cards.erase(remove(cards.begin(),cards.end(),'C'),cards.end());
                    
                }
            }
            if(check[2]==3){
                for(int j =0;j<3;j++){
                    cards.erase(remove(cards.begin(),cards.end(),'A'),cards.end());
                    
                }
            }
        
            
            
        }
        
    }
    
    
    
}
int Hand::rateOfExchange(){
    if(D->getSetsReturned()==0)
        return 4;
    if(D->getSetsReturned()==1)
        return 6;
    if(D->getSetsReturned()==2)
        return 8;
    if(D->getSetsReturned()==3)
        return 10;
    if(D->getSetsReturned()==4)
        return 12;
    if(D->getSetsReturned()==5)
        return 15;
    if(D->getSetsReturned()>=6)
        return 15+(D->getSetsReturned()-5)*5;//check to make sure this number is correct ahah
    return 0;//idk man
}



