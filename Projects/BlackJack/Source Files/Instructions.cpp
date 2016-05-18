#include<vector>
#include "../Header Files/Instructions.h"

Instructions::Instructions()
{
    
}

void Instructions::init()
{
    cout << "~~~~~~~~~~BLACKJACK~~~~~~~~~~~\n";
    cout << "Basically you can pick up as many card as you want" << endl;
    cout << "Your card total cant add up to 21." << endl;
    cout << "Who Ever Has the biggest total without exceding MAX, wins." << endl;
    cout << "Good Luck! May the odds be ever in your favor xD! " << endl;
    cout << "\n\nDo you want to play single player, or multiplayer? (Enter 0 for single player, 1 for multiplayer)" << endl;
    std::cin >> MODE;
    this -> initGames(&MODE);
}

void Instructions::initGames(unsigned short int *MODE)
{
    if((*MODE) == 0 )
            spdmg.startGame();
        
    else
            mpdmg.startGame();
}


Instructions::~Instructions()
{
}
