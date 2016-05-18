#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/Instructions.cpp"

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
	Instructions inst;
};
