#ifndef DECK_H
#define DECK_H
#include <vector>


class deck
{
    public:
        deck();
        int getDeck();
        void setDeck(int nC);
        void createDeck();






    protected:

    private:
        std::vector<char> decko;
        std::vector<int> share;
        int noCards;
};




#endif // DECK_H
