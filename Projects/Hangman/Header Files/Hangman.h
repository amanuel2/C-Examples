#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/Drawer.cpp"
#include "../Source Files/Dictonary.cpp"

using std::cout;
using std::endl;
using std::string;


class Hangman
{
public:
	Hangman();
	~Hangman();
	void run(int TEMP_MODE);
private:
    std::vector<char> randStringVec;
    string userGuessLetter;
    Dictonary dictonary;
    string randomString;
    Drawer hgmnDraw;
    void mainGame();
    void drawHangMan(int attempts, int mode);
    void checkIfItEquals(string guessLet);
    void deleteSimilarLet(string str);
    void stringToVec();
    void checkFail();
    void mainGameLoop();
    int attemptsMadeBad = 0;
    int attemptsMadeGood = 0;
    bool correctGs;
    int MODE;
};
