#include<vector>
#include "../Header Files/MultiPlayer.h"

MultiPlayer::MultiPlayer()
{
    srand(time(NULL));
    _turn = Turn::PLAYER1;
}

int myRandMult(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}

void MultiPlayer::startGame()
{
    this -> connectionPlayer(&_turn);
}

void MultiPlayer::connectionPlayer(Turn *turn)
{
    if (ooS == OptOut::TRUEOPT)
    {
        cout << "******************* BOTH OF YOU PLAYERS OPT OUT. CALCULATING POINTS ********************\n";
        this -> evaluateBigger(&player1Amount, &player2Amount);
        exit(1);
    }
    
    if((*turn) == Turn::PLAYER1)
            this -> player1Turn(startingOne);
    
    else
    {
        this -> player2Turn(startingTwo);
    }
            
}

void MultiPlayer::player1Turn(bool &starting)
{
    if(starting)
    {
            int player1TurnRandStarting1 = myRandMult(0,10);
            int player1TurnRandStarting2 = myRandMult(0,10);
            evaluatePlayer1(&_turn, player1TurnRandStarting1, player1TurnRandStarting2);
            starting = false;
            _turn = Turn::PLAYER2;
            
            if(startingPrintOne)
                startingPrintOne = false;
            else
                this -> printScore();
                
            this -> connectionPlayer(&_turn);
    }
    else
    {
        int choice = 6;
        try
        {
            cout << "Do you want to add cards Player1?( 0 for No, 1 for YES)\n";
            std::cin >> choice;
            if(choice != 0 && choice != 1)
                throw "Unsported Number";
        }
        catch(const char* exc)
        {
            if(true)
                exit(1);
        }
        
        if(choice == 0)
        {
            if(ooS == OptOut::PARTIAL)
                 ooS = OptOut::TRUEOPT;
            else
                 ooS = OptOut::PARTIAL;
                 
            _turn = Turn::PLAYER2;
            this -> connectionPlayer(&_turn);
        }
        else
        {
           ooS = OptOut::FALSEOPT;
           int randNumber1 = myRandMult(0,10);
           evaluateNonStart(&_turn, randNumber1);
           _turn = Turn::PLAYER2;
           this -> connectionPlayer(&_turn);
        }
        
    }
}

void MultiPlayer::evaluateNonStart(Turn *turn, int num)
{
    if((*turn) == Turn::PLAYER1)
    {
            player1Amount += num;
            player1Cards.push_back(num);
            
            if(player1Amount > 21)
            {
                cout << "PLAYER 1 YOU HAVE LOST!! \n";
                this -> endPrintScore();
                exit(1);
            }
    }
    else
    {
            player2Amount += num;
            player2Cards.push_back(num);
            if(player2Amount > 21)
            {
                cout << "PLAYER 2 YOU HAVE LOST!! \n";
                this -> endPrintScore();
                exit(1);
            }
    }
}

void MultiPlayer::evaluatePlayer1(Turn *turn, int player1F, int player1S)
{
    player1Amount = player1Amount + player1F + player1S;
    player1Cards.push_back(player1F);
    player1Cards.push_back(player1S);
}

void MultiPlayer::evaluatePlayer2(Turn *turn, int player2F, int player2S)
{
    player2Amount = player2Amount + player2F + player2S;
    player2Cards.push_back(player2F);
    player2Cards.push_back(player2S);
}

void MultiPlayer::player2Turn(bool &starting)
{
     if(starting)
    {
            int player2TurnRandStarting1 = myRandMult(0,10);
            int player2TurnRandStarting2 = myRandMult(0,10);
            evaluatePlayer2(&_turn, player2TurnRandStarting1, player2TurnRandStarting2);
            starting = false;
            _turn = Turn::PLAYER1;
            
            if(startingPrintTwo)
                startingPrintTwo = false;
            else
                this -> printScore();
                
            this -> connectionPlayer(&_turn);
    }
    else
    {
        int choice = 6;
        try
        {
            cout << "Do you want to add cards Player2?( 0 for No, 1 for YES)\n";
            std::cin >> choice;
            if(choice != 0 && choice != 1)
                throw "Unsported Number";
        }
        catch(const char* exc)
        {
            if(true)
                exit(1);
        }
        
        if(choice == 0)
        {
            if(ooS == OptOut::PARTIAL)
                 ooS = OptOut::TRUEOPT;
            else
                 ooS = OptOut::PARTIAL;
            _turn = Turn::PLAYER1;
            this -> connectionPlayer(&_turn);
        }
        else
        {
            ooS = OptOut::FALSEOPT;
           int randNumber2 = myRandMult(0,10);
           evaluateNonStart(&_turn, randNumber2);
           _turn = Turn::PLAYER1;
        
            if(startingPrintTwo)
                startingPrintTwo = false;
            else
                this -> printScore();
                
           this -> connectionPlayer(&_turn);
        }
        
    }

}


void MultiPlayer::printScore()
{
 cout << "PLAYER 1 HAS " << player1Amount << " Points!\n";   
 cout << "PLAYER 2 HAS " << player2Amount << " Points!\n"; 

}

void MultiPlayer::evaluateBigger(int *player1Points, int *player2Points)
{
    if((*player1Points) > (*player2Points))
    {
        cout << "~~~~~ PLAYER 1 YOU HAVE WON! ~~~~~ \n";
        this -> endPrintScore();
    }
    else
    {
        cout << "~~~~~ PLAYER 2 YOU HAVE WON! ~~~~~ \n";
        this -> endPrintScore();
    }
}

void MultiPlayer::endPrintScore()
{
    int countPlayer1 = 1, countPlayer2 = 1;
    cout << "------------HISTORY------------" << endl;
    cout << "Player1 Cards pulled" << endl;
    for(std::vector<int>::iterator it=player1Cards.begin(); it!=player1Cards.end(); it++)
    {
        cout << countPlayer1 << " : " << *it << endl;
        countPlayer1++;
    }
    cout << "Player2 Cards pulled" << endl;
     for(std::vector<int>::iterator it=player2Cards.begin(); it!=player2Cards.end(); it++)
    {
        cout << countPlayer2 << " : " << *it << endl;
        countPlayer2++;
    }
    cout << "-------------------------------" << endl;
}


MultiPlayer::~MultiPlayer()
{
}
