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

	enum class GameState : char
	{
		PLAY,
		EXIT
	};

	MainGame();
	~MainGame();
	void run();
private:
	void initalizeSystems();
	void mainLoop();
	Instructions inst;
	GameState _gameState;
};
