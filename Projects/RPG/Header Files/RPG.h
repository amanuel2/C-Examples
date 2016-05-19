#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <math.h> 
#include "../Source Files/Character.cpp"
#include "../Source Files/Enemy.cpp"

#define PI 3.14159265
#define PI2 6.2820894

using std::cout;
using std::endl;
using std::string;


class RPG
{
public:

	//States, Player can achieve 
	//While facing Enemy
	//1) Attack,
	//2) Defense
	//4) Health-Potion
	//3) Flee
	
	enum class PLAYER_STATES : char
	{
		ATTACK,
		DEFENSE,
		POTION,
		FLEE
	};
	
	RPG();
	~RPG();
	void initRPG();
private:
	Character _character;
	Enemy _enemies[10];
	string STATE_CHOSEN_CIN = "";
	PLAYER_STATES __playerStates;
	//ENEMY_STAGE, staging.
	int ENEMY_STAGE = 0; //Justice, i remember you said dont do int variable name; IDK How to fix...
	//Initalize User Character
	void initChar(Character &_char, string name, string age, string gender);
	//Updating Enemy Stats
	void updateEnemies(std::map<string, int> &STATS,Enemy enemy);
	//Prining user Character
	void printChars(std::map<string,int> print);
	//Handles states character uses to enemies
	void HandleStates(PLAYER_STATES &_state);
	//Handles the attack state
    void attackModeState(std::map<string,int> &statsParam, Enemy enemy);
    //INitalize Enemy, stats, profiles, etc..
	void initEnemies();
	//Loop of game... encountring enemies, etc..
	void gameLoop();
	//MainGame
	void Game();
	//Continuing State
	void continueState();
};
