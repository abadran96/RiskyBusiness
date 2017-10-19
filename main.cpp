#include <iostream>
#include "Dice.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//prototype
void SetUpDice();
void RollDice();
// Dice object
Dice dice;
Dice dice2;

int main()
{
    int stop=0;
    //validator
	while (stop != -1)
    {
        //game start
		SetUpDice();
		RollDice();
		cout << "Press -1 to quit the game or press any other key to continue" << endl;
		cin >> stop;
    }
        return 0;

}

//game
void SetUpDice()
    {
        int input = 0;
        int input2 = 0;
        cout << "Welcome to the dice class" << endl;
	//validator
	do
	{
		cout << "Please input the numbers of dice you want to roll first(1-3)" << endl;
		cin >> input;
	} while (!(1 <= input && input <=3));

	do
    {
		cout << "Please input the numbers of dice you want to roll second(1-3)" << endl;
		cin >> input2;
	}while (!( 1<=input2 && input2 <= 3));
	//seed
	srand(time(NULL));
	//set the number
    dice.setNumberOfDice(input);
    dice2.setNumberOfDice(input2);

    }
    //roll dice
void RollDice()
{
	cout << "           first set of dice:" << endl;
	cout << "___________________________________________________" << endl;
	//calling functions
	dice.DiceRoll();
	cout << "___________________________________________________" << endl;
	dice.store();
	dice.Percent();
	cout << endl;
    cout << "           second set of dice:" << endl;
	cout << "____________________________________________________" << endl;
	dice2.DiceRoll();
	cout << "____________________________________________________" << endl;
	dice2.store();
	dice2.Percent();

}


