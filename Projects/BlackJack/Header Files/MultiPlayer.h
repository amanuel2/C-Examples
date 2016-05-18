#pragma once
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;


class MultiPlayer
{
public:

	enum class Turn : char
	{
		PLAYER1,
		PLAYER2
	};
	enum class OptOut : char
	{
		TRUEOPT,
		PARTIAL,
		FALSEOPT
	};

	MultiPlayer();
	~MultiPlayer();
	void startGame();
private:
	Turn _turn;
	OptOut ooS;
	bool startingPrintOne = true,startingPrintTwo = true;
	std::vector<int> player1Cards, player2Cards;
	bool startingOne = true, startingTwo = true;
	int player1Amount = 0, player2Amount = 0;
	void evaluatePlayer1(Turn *turn, int player1F, int player1S);
	void evaluatePlayer2(Turn *turn, int player2F, int player2S);
	void evaluateBigger(int *player1Points, int *player2Points);
	void connectionPlayer(Turn *turn);
	void evaluateNonStart(Turn *turn, int num);
	void player1Turn(bool &starting);
	void player2Turn(bool &starting);
	void printScore();
	void endPrintScore();
};
