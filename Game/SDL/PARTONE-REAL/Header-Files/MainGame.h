#pragma once
#include<Windows.h>
#include<SDL.h>
#include<GL/glew.h>
class MainGame
{
public:
	MainGame(int width, int height);
	~MainGame();

	void run();

	void initSystem();

private:
	int _screenWidth;
	int _screenHieght;
	SDL_Window *__window;
};

