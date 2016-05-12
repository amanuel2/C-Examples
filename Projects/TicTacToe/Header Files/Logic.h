#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include <ctime>
#include "../Source Files/MainGraph.cpp"

using std::cout;
using std::endl;
using std::string;


class Logic
{
public:
	Logic();
	~Logic();
	void run(std::vector<int> &avaiable, std::vector<int> &taken);

private:
    MainGraph mgraph;
    void drawSt();
    void returnPos(short int &posAI, std::vector<int> &avaiable, std::vector<int> &taken);
    void deleteVec(std::vector<int> &avaiable, std::vector<int> &taken, short int posPlayer, short int posAI);
};
