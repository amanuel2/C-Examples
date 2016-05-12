#include<vector>
#include "../Header Files/MainGame.h"

MainGame::MainGame()
{
    _turn = Turn::PLAYER;
}

void MainGame::initGrids()
{
    vectorGridsInit(&_availableGrids,&_takenGrids);
}
void MainGame::run()
{
    initGrids();
    mainLoop();
}

void MainGame::vectorGridsInit(std::vector<int> *avaiable, std::vector<int> *taken){
    for(int i=1; i<=9; i++)
        avaiable->push_back(i);
    
}

void MainGame::mainLoop(){
    //_gameState != GameState::EXIT
    while(true){
        logic.run(_availableGrids,_takenGrids);
    }
}

MainGame::~MainGame()
{
}
