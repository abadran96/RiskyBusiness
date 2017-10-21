#ifndef deck_H
#define deck_H
#include <vector>


class deck
{
    public:
        deck();

            void setCardNo(int nO);
            int getCardNo();
            char createDeck(int amount);//will create the deck obj
            void Draw();//will draw from deck and will put them in the hand obj
            int exchange(int n);//will













    private:

        int noCards;
        int noReinforcement;
        std::vector<char> theDeck;
        std::vector<char> globalVector;
        std::vector<int> share;
        std::vector<int> check;


};

#endif // deck_H
