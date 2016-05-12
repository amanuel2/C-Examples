#pragma once
#include<iostream>
#include<string>
#include "../Source Files/DrawPlayer.cpp"

using std::cout;
using std::endl;
using std::string;


class MainGraph
{
public:
	MainGraph();
	~MainGraph();
	void draw();
	void drawX(int position, string charr);

private:
    DrawPlayer dp;
};

