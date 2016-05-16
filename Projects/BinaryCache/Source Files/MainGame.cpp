#include<vector>
#include "../Header Files/MainGame.h"

MainGame::MainGame()
{
    _gameState = GameState::PLAY;
}

void MainGame::run()
{
    initalizeSystems();
    mainLoop();
}

void MainGame::initalizeSystems()
{
    
}

void MainGame::mainLoop()
{
    while(_gameState != GameState::EXIT)
    {
        inst.printTableOfC();
    }
}

MainGame::~MainGame()
{
}
