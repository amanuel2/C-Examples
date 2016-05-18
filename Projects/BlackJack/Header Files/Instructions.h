#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/MultiPlayer.cpp"
#include "../Source Files/SinglePlayer.cpp"

using std::cout;
using std::endl;
using std::string;


class Instructions
{
public:

	Instructions();
	~Instructions();
	void init();
	void initGames( unsigned short int *MODE);

private:
    MultiPlayer mpdmg;
    SinglePlayer spdmg;
    unsigned short int MODE;
};
