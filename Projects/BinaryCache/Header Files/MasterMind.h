#pragma once
#include<iostream>
#include <bitset>
#include<string>
#include<vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;


class MasterMind
{
public:
	MasterMind();
	~MasterMind();
	void init();
private:
	unsigned int positonCorrect = 0, actuallyCorrect = 0;
	std::vector<int> binaries, playerTryBin;
	std::vector<char> numbers;
	string binaryKep;
	int binary,binaryCin;
    int randNum, DEBUGGER;
    void startGame();
	void startGameInst();
	void convertToBinary(int n);
	void evaluateNum(int &bin);
	void initStartGame();
	void gameLoopGame();
	void gameLoopFini();
	void evaluatePosition();
	void evaluateCorrection();
};
