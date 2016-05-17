#include<vector>
#include "../Header Files/Hangman.h"

Hangman::Hangman()
{
}

void Hangman::run(int TEMP_MODE)
{
    MODE = TEMP_MODE;
    this -> mainGame();
    this -> mainGameLoop();
}


void Hangman::mainGame()
{
    dictonary.init();
    randomString = dictonary.randomItem();
    stringToVec();
}

void Hangman::stringToVec()
{
    for(std::string::iterator it = randomString.begin(); it != randomString.end(); ++it) 
    {
        randStringVec.push_back(*it);
    }
}


void Hangman::mainGameLoop()
{
    while(true)
    {
        try
        {
           cout << " \n Guess A Letter (MUST BE A LETTER OR EXIT) \n";
           std::cin >> userGuessLetter;
           if(userGuessLetter.length() > 1)
                throw "Too Big Of a letter";
        } 
        
        catch(const char* exc)
        {
            if(true)
            {
                exit(1);
            }
        }
            
         cout << "You typed " << userGuessLetter << endl;
         checkIfItEquals(userGuessLetter);
         
         if(randStringVec.size() <= 0)
         {
            cout << "~~~~~~~~~CONGRATZ! YOU BIT HANGMAN!!~~~~~~~~~~";
            exit(1);
         }
    }

}

void Hangman::checkIfItEquals(string guessLet)
{
    correctGs = false;
        for(std::vector<char>::iterator it = randStringVec.begin(); it!=randStringVec.end(); it++)
        {
            std::string charStr = string(1, *it);
            if(guessLet.compare(charStr) == 0)
            {
                cout << "GOOD JOB.. THERE IS A SIMMILAR LETTER!" << endl;
                deleteSimilarLet(charStr);
                attemptsMadeGood++;
                correctGs = true;
                break;
            }
        }
        
    if(correctGs == false)
    {
        if(MODE == 0)
        {
            if(attemptsMadeBad >= 9)
            {
                hgmnDraw.drawHangMan(attemptsMadeBad,MODE);
                cout << "YOU ARE JUST A LOSER! YOU LOST TO HANGMAN! " << endl;
                exit(1);
            }   
        }
        else if(MODE == 1)
        {
            if(attemptsMadeBad >= 7)
            {
                hgmnDraw.drawHangMan(attemptsMadeBad,MODE);
                cout << "YOU ARE JUST A LOSER! YOU LOST TO HANGMAN! " << endl;
                exit(1);
            }  
        }
        else if(MODE == 2)
        {
            if(attemptsMadeBad >= 4)
            {
                hgmnDraw.drawHangMan(attemptsMadeBad,MODE);
                cout << "YOU ARE JUST A LOSER! YOU LOST TO HANGMAN! " << endl;
                exit(1);
            }  
        }
        else if(MODE == 3)
        {
            if(attemptsMadeBad == 1)
            {
                hgmnDraw.drawHangMan(attemptsMadeBad,MODE);
                cout << "YOU ARE JUST A LOSER! YOU LOST TO HANGMAN! " << endl;
                exit(1);
            }  
        }
        cout << "FAILUER! You MADE A WRONG DECISION! " << endl;
        attemptsMadeBad++;
        hgmnDraw.drawHangMan(attemptsMadeBad,MODE);
    }
}

void Hangman::deleteSimilarLet(string str)
{
        for(std::vector<char>::iterator it = randStringVec.begin(); it!=randStringVec.end(); it++)
        {
            std::string charStr = string(1, *it);
             if(charStr.compare(str) == 0)
             {
                  randStringVec.erase(std::remove(randStringVec.begin(), randStringVec.end(), (*it)), randStringVec.end());   
             }
        }
}

Hangman::~Hangman()
{
}
