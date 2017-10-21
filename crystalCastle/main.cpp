#include <iostream>
#include "deck.h"
#include <vector>


using namespace std;


int main()
{

    deck hw;

    cout<<endl;
    hw.createDeck(5);
    hw.Draw();

    return 0;
}
