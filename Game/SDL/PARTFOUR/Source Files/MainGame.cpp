#include "MainGame.h"



MainGame::MainGame(int width, int height) :_widthGame(width), _heightGame(height)
{
	_currentState = GameState::PLAY;
	__window = NULL;
}

void MainGame::run() {
	initSystems();
	//Initalize Sprite. Code in Sprite.cpp
	_sprite.init(-1.0f,-1.0f,1.0f,1.0f);
	gameLoop();
}
void MainGame::checkQuit() {
	std::string quitOption;
	std::cout << "Are you sure you want to quit?(Y or N)" << std::endl;
	std::cin >> quitOption;

	std::transform(quitOption.begin(), quitOption.end(), quitOption.begin(), tolower);

	if (quitOption.compare("y") == 0) {
		_currentState = GameState::EXIT;
		gameLoop();
	}
	else {
		_currentState = GameState::PLAY;
		gameLoop();
	}
}
void fatalError(std::string err, GameState *state) {
	std::cout << err << std::endl;
	*state = GameState::EXIT;
	SDL_Quit();
	exit(1);
}
void MainGame::initSystems() {
	//Initalize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	__window = SDL_CreateWindow(
		"MySelfEngine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_widthGame,
		_heightGame,
		SDL_WINDOW_OPENGL
	);

	if (__window == NULL)
		fatalError("COULD NOT INITALIZE WINDOW... ABORTING!", &_currentState);


	SDL_GLContext glConx = SDL_GL_CreateContext(__window);
	if (glConx == NULL)
		fatalError("Could not create GL Context", &_currentState);

	//Sets up Extension. For
	//Unsported Hardware
	GLenum errorGl = glewInit();

	if (errorGl != GLEW_OK)
		fatalError("Couldnt Initalize Glew!", &_currentState);

	//Stops Flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	//Gives Blue Background
	glClearColor(0.0f, 0.0f, 1.0f, 1.0);
}

void MainGame::processInput() {
	SDL_Event evt;

	while (SDL_PollEvent(&evt) == 1) {
		switch (evt.type) {
		case SDL_QUIT:
			checkQuit();
			break;
		case SDL_FINGERMOTION:
			std::cout << " Current X FINGER" << evt.tfinger.x << std::endl;
			std::cout << " Current Y FINGER" << evt.tfinger.y << std::endl;
			break;
		case SDL_MOUSEMOTION:
			std::cout << " Current X " << evt.motion.x << std::endl;
			std::cout << " Current Y " << evt.motion.y << std::endl;
			std::ofstream FileMouse("userMouseData.txt");
			FileMouse << " Current X " << evt.motion.x << " Current Y " << evt.motion.y << std::endl;
			FileMouse.close();
			break;
		}
	}
}

void MainGame::gameLoop() {
	
	while (_currentState != GameState::EXIT) {
		processInput();
		draw();
	}
}

void MainGame::draw() {
	//Clearing The Depth.
	glClearDepth(1.0);

	//Both Must Be Called in order to draw!
	//Clears Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Draw Sprite. Code in Sprite.cpp
	_sprite.draw();

	/*Swaps Window, because we initalized to windows
	When we did SDL_GL_DOUBLEBUFFER.*/
	SDL_GL_SwapWindow(__window);
}

MainGame::~MainGame()
{
}
