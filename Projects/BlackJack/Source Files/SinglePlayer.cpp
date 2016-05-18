#include<vector>
#include "../Header Files/SinglePlayer.h"

SinglePlayer::SinglePlayer()
{
    srand(time(NULL));
}

int myRand(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}

void SinglePlayer::startGame()
{
   
            cout << "Starting out with two cards...." << endl;
            int randomCardStarterOnePlayer = myRand(0,10);
            int randomCardStarterTwoPlayer = myRand(0,10);
            int randomCardStarterOneAI = myRand(0,10);
            int randomCardStarterTwoAI = myRand(0,10);
            this -> calculateRandomStarter(randomCardStarterOnePlayer,
                                           randomCardStarterTwoPlayer,
                                           randomCardStarterOneAI,
                                           randomCardStarterTwoAI);
            
            while(true)
            {
                       try
                        {
                            cout << "YOU CURRENTLY HAVE : " << amountPlayer << endl;
                            cout << "Computer CURRENTLY HAS : " << amountAI << endl;
                            cout << "Do you want to take a card? (0 for NO, 1 for YES) \n";
                            std::cin >> choiceTakePlayer;
                            if(choiceTakePlayer != 0 && choiceTakePlayer != 1)
                                throw "Unsported Number";
                        }
                        catch(const char* exc)
                        {
                            if(true){
                                this -> endPrint();
                                exit(1);
                            }
                        }
                        
                        takeCardCheckPlayer(&choiceTakePlayer);
            }
  
    
}

void SinglePlayer::takeCardCheckAI(const int choice)
{
    if((choice) == 1)
    {
                if(amountAI <= 17)
                {
                        cout << "Generating Random Card FOR AI.... \n";
                        int randomCard = myRand(0,10);
                        amountAI += randomCard;
                        AICards.push_back(randomCard);
                        cout << "Generated " << randomCard << endl;
                        if(amountAI > 21)
                        {
                            cout << "~~~~~~~CONGRATZ YOU WON!!!<AI-EXCEDED>~~~~~~~" << endl;
                            this -> endPrint();
                            exit(1);
                        }
                }
                
                else
                {
                    cout << " AI REFUSES TO DRAW! " << endl;
                }

    }
}

void SinglePlayer::takeCardCheckPlayer(int *choice)
{
    if((*choice) == 1)
    {
        cout << "Generating Random Card For you.... \n";
        int randomCard = myRand(0,10);
        amountPlayer += randomCard;
        playerCards.push_back(randomCard);
        cout << "Generated " << randomCard << endl;
        if(amountPlayer > 21)
        {
            cout << "YOU HAVE EXCEDED MAX! YOU ARE A LOSER!" << endl;
            this -> endPrint();
            exit(1);
        }
        this -> takeCardCheckAI(1);
    }
    else
    {
        if(amountAI <= 17)
        {
            this -> takeCardCheckAI(1);
        }
        string winner = calculateWinner(amountPlayer,amountAI);
        if(winner.compare("Player"))
        {
            cout << "~~~~~~~CONGRATZ YOU WON!!!~~~~~~~" << endl;
            this -> endPrint();
            exit(1);
        }
        else
        {
            cout << "YOU HAVE EXCEDED MAX! YOU ARE A LOSER!" << endl;
            this -> endPrint();
            exit(1);
        }
    }
}

string SinglePlayer::calculateWinner(int Player, int AI)
{
    return(Player <= AI ? " Player " : " Computer ");
}

void SinglePlayer::calculateRandomStarter(int randomOnePlayer, int randomTwoPlayer, int randomOneAI, int randomTwoAI)
{
    amountPlayer = amountPlayer + randomOnePlayer + randomTwoPlayer;
    playerCards.push_back(randomOnePlayer);
    playerCards.push_back(randomTwoPlayer);
    
    amountAI = amountAI + randomOneAI + randomTwoAI;
    AICards.push_back(randomOneAI);
    AICards.push_back(randomTwoAI);
}

void SinglePlayer::endPrint()
{
    cout << "------------HISTORY------------" << endl;
    cout << "Your Cards you pulled" << endl;
    for(std::vector<int>::iterator it=playerCards.begin(); it!=playerCards.end(); it++)
    {
        cout << *it << endl;
    }
    cout << "Computers Cards AI pulled" << endl;
     for(std::vector<int>::iterator it=AICards.begin(); it!=AICards.end(); it++)
    {
        cout << *it << endl;
    }
    cout << "-------------------------------" << endl;
}

SinglePlayer::~SinglePlayer()
{
}
