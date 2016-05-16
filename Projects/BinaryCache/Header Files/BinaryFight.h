#pragma once
#include<iostream>
#include <bitset>
#include<string>
#include<vector>
#include <algorithm>
#include "../Source Files/Timer.cpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;


class BinaryFight
{
public:
	BinaryFight();
	~BinaryFight();
	void init();
private:
    Timer timer;
    std::vector<int> timesPassedVec, correctF, correctS, correctT;
    bool correctFB, correctSB, correctTB;
    int rand1,rand2,rand3;
    float averageNum = 0;
    int userGs1,userGs2,userGs3;
    void startGame();
    void printInst();
    void convertToBinary(int n,std::vector<int> &correct);
    void checkCorrectness(int userGuess, std::vector<int>AICORRECT, bool &correctB);
    void binaryRounds(int count);
    void resultsPrt();
};
