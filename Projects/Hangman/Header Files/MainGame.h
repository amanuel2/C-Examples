#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/Hangman.cpp"

using std::cout;
using std::endl;
using std::string;


class MainGame
{
public:

	MainGame();
	~MainGame();
	void run();
private:
    int TEMP_MODE = 0;
 	Hangman hmdmg;
	void startGame();
	void printInstructions();
};
