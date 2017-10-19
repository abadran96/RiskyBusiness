#ifndef DICE_H
#define DICE_H
#include <vector>
#pragma once

class Dice
{
    public:
        Dice();

        int getNumberOfDice();
        void setNumberOfDice(int x);

        int DiceRoll();
        void store();
        void Percent();

    protected:
    private:
        int x;
	    int numberOfDice;
	    int DiceCount;
	    int turns;
        int DiceNumber[6]={0,0,0,0,0,0};
        std::vector<int> DiceOutcome{0,0,0};
};

#endif // DICE_H
