#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "../Source Files/Logic.cpp"

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
	
	enum class Turn : char
	{
		PLAYER,
		AI
	};

	MainGame();
	~MainGame();
	void run();

private:
	std::vector<int> _availableGrids;                                
  	std::vector<int> _takenGrids;    
	GameState _gameState = GameState::PLAY;
	Logic logic;
	Turn _turn;
	void initGrids();
	void mainLoop();
	void vectorGridsInit(std::vector<int> *avaiable, std::vector<int> *taken);

};
