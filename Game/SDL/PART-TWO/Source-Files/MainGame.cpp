#include "MainGame.h"


MainGame::MainGame(int width, int height):_screenWidth(width), _screenHieght(height)
{
	__window = NULL;
	__gameState = GameState::PLAY;
}

void MainGame::run() {
	initSystem();
	gameLoop();
}

void MainGame::quitCheck() {
	std::string quitOption;
	std::cout << "Are you sure you want to quit?(Y or N)" << std::endl;
	std::cin >> quitOption;

	std::transform(quitOption.begin(), quitOption.end(), quitOption.begin(), tolower);

	if (quitOption.compare("y") == 0){
		__gameState = GameState::EXIT;
		gameLoop();
	}
	else {
		__gameState = GameState::PLAY;
		gameLoop();
	}

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

void MainGame::processInput() {
	SDL_Event evt;
	//If there is an Event
	while (SDL_PollEvent(&evt) == 1) {
		switch (evt.type) {
		case SDL_QUIT:
			quitCheck();
			break;
		case SDL_MOUSEMOTION:
			std::cout << " Current X " << evt.motion.x << std::endl;
			std::cout << " Current Y " << evt.motion.y << std::endl;
			break;
		}
	}

}
void MainGame::gameLoop() {

	while (__gameState != GameState::EXIT) {
		processInput();
	}

}
MainGame::~MainGame()
{
}
