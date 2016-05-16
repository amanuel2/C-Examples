#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/MasterMind.cpp"
#include "../Source Files/BinaryFight.cpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;


class Instructions
{
public:
    
    enum class Games : char
	{
		MASTERMIND,
		BINARYTIME
	};
	
	Instructions();
	~Instructions();
	
	void printTableOfC();
	void printAbout();
	void printGames();
	void printHelp();
private:
    short unsigned int swh,gameChoice;
    string aboutCheck,helpCheck;
    Games gameChoiceEn;
    MasterMind mmdg;
    BinaryFight bfdg;
};
