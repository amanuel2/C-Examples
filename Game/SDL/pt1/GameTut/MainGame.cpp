#include "MainGame.h"



MainGame::MainGame(int width, int height):_screenWidth(width), _screenHieght(height)
{
	__window = NULL;
}

void MainGame::run() {
	initSystem();
}

void MainGame::initSystem() {
	//Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Creation Window
	__window = SDL_CreateWindow(
		"Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_screenWidth,
		_screenHieght,
		SDL_WINDOW_OPENGL
	);
}

MainGame::~MainGame()
{
}
