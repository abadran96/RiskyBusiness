#ifndef HAND_H
#define HAND_H
#include <vector>


class hand
{
    public:
        hand();
        void createHand(int x);

    protected:

    private:
    std::vector<char> handVector;
    int userChoice;
    int noChoice;

};

#endif // HAND_H
