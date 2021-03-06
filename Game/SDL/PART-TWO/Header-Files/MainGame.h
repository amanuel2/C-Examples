#pragma once
#include<Windows.h>
#include<SDL.h>
#include<GL/glew.h>
#include<string>
#include <algorithm>
#include<iostream>


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
	void initSystem();
	void processInput();
	void gameLoop();
	void quitCheck();

	int _screenWidth;
	int _screenHieght;
	GameState __gameState;
	SDL_Window *__window;
};

