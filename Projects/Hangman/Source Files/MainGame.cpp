#include<vector>
#include "../Header Files/MainGame.h"

MainGame::MainGame()
{
}

void MainGame::run()
{
    this -> printInstructions();
    this -> startGame();
}


void MainGame::printInstructions()
{

    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HANGMAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";
    cout << "I will give you a technological term to figure out... " << endl;
    cout << "You will guess a letter each time.. If you figure it out by 6 letters then good job! " << endl;
    cout << "If not, oh well YOUR A FAILURE! " << endl;
    cout << "Good Luck, May the odds be ever in your favor xD! \n\n\n" << endl;
    
    cout << "What MODE Would you like the Hangman Game to be at? Options? \n 0 = Easy Mode, you get 10 lifes. \n 1 = Medium Mode, you get 7 lifes. \n 2 = Hard Mode, you get 4 lifes. \n 3 = EXTREMELY HARD MODE, you get 1 life ) \n";
    std::cin >> TEMP_MODE;
    cout << "MODE TEMP " << TEMP_MODE << endl;
    if(TEMP_MODE != 0 && TEMP_MODE != 1 && TEMP_MODE != 2 && TEMP_MODE != 3)
    {
        cout << "Exiting Because you want to crash this game... " << endl;
        exit(1);
    }
}
void MainGame::startGame(){
    hmdmg.run(TEMP_MODE);
}

MainGame::~MainGame()
{
}
