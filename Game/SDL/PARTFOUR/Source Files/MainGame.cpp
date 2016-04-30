#include "MainGame.h"

MainGame::MainGame(int width, int height):_screenWidth(width), _screenHieght(height)
{
	__window = NULL;
	__gameState = GameState::PLAY;
}

void fatalError(std::string errString) {
	std::cout << errString << std::endl; int tmp;
	std::cout << "Press Any Key to Quit... ";
	std::cin >> tmp;
	//Quits out of SDL
	SDL_Quit();
	//Exits out of Debugger
	exit(1);
}

void MainGame::run() {
	//Initalizes Systems First
	initSystem();

	_sprite.init(-1.0f,-1.0f,1.0f,1.0f);

	//Then Loops until user Exits
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
	//Checks for any errors..
	if (__window == NULL)
		fatalError("Could Not Create SDL...");


	SDL_GLContext glConx = SDL_GL_CreateContext(__window);
	if (glConx == NULL)
		fatalError("Could not create GL Context");

	//Sets up Extension. For
	//Unsported Hardware
	GLenum errorGl = glewInit();

	if (errorGl != GLEW_OK)
		fatalError("Couldnt Initalize Glew!");

	//Stops Flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	//Gives Blue Background
	glClearColor(0.0f, 0.0f, 1.0f, 1.0);
}

void MainGame::drawGame() {
	//Clearing The Depth.
	glClearDepth(1.0);

	//Both Must Be Called in order to draw!
	//Clears Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	_sprite.draw();


	/*Swaps Window, because we initalized to windows
	When we did SDL_GL_DOUBLEBUFFER.*/
	SDL_GL_SwapWindow(__window);
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
		/**
		**Proccess input, so AI Can interact
		**With User
		*/
		processInput();

		drawGame();
	}

}
MainGame::~MainGame()
{
}
