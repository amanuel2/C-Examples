#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using std::cout;
using std::endl;
using std::string;


class SinglePlayer
{
public:

	SinglePlayer();
	~SinglePlayer();
	void startGame();
private:
    int choiceTakePlayer;
    int amountPlayer = 0, amountAI = 0;
    std::vector<int> playerCards, AICards;
    void calculateRandomStarter(int randomOnePlayer, int randomTwoPlayer, int randomOneAI, int randomTwoAI);
    void takeCardCheckPlayer(int *choice);
    void takeCardCheckAI(const int choice);
    string calculateWinner(int Player, int AI);
    void endPrint();
};
