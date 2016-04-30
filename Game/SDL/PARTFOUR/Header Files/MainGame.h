#pragma once
#include<Windows.h>
#include<SDL.h>
#include<GL/glew.h>
#include<string>
#include <algorithm>
#include<iostream>
#include<fstream>
#include "Sprite.h"
enum class GameState {
	PLAY,
	EXIT
};
class MainGame
{
public:
	MainGame(int width, int height);
	~MainGame();
	void run();
private:
	void initSystems();
	void draw();
	void processInput();
	void checkQuit();
	void gameLoop();
	int _widthGame, _heightGame;
	GameState _currentState;
	SDL_Window *__window;
	Sprite _sprite;
};

