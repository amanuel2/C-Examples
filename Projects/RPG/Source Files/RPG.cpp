#include<vector>
#include "../Header Files/RPG.h"

RPG::RPG()
{
}



void RPG::initRPG()
{
   string name,ageInt,age,gender;
   cout << "Initalizing RPG GAME...." << endl;
   cout << "What Name would you like? " << endl;
   std::cin >> name;
   cout << "What Age would you like? " << endl;
   std::cin >> ageInt;
   age = std::stoi(ageInt);
   cout << "What Gender would you like? " << endl;
   std::cin >> gender;
   this -> initChar(_character, name, age, gender);
   this -> initEnemies();
   this -> Game();
}

void RPG::Game()
{
    this -> printChars(_character.getStats());
    
    while(true)
    {
        try
        {
            if(ENEMY_STAGE >= 10)
            {
                throw "Game Finished";
            }
            this -> continueState();
            this -> gameLoop();
            ENEMY_STAGE++; 
        }
        catch(const char* exc)
        {
            cout << "~~~~~YOU WON!!!~~~~ \n";
            exit(1);
        }
        
    }
}

void RPG::initEnemies()
{
    for(int i=0; i< 10; i++)
    {
        _enemies[i].init();
    }
}

void RPG::updateEnemies(std::map<string, int> &STATS, Enemy enemy)
{
        STATS = enemy._getStats();
}
void RPG::gameLoop()
{
    //Game Loop, where i loop a new Enemy, every time
    //The Player Defeats One.
    std::map<string, string> paramPROFILE = _enemies[ENEMY_STAGE]._getProfile();
    std::map<string, int>paramSTATS = _enemies[ENEMY_STAGE]._getStats();
    cout << "~~~~~~~~~~~NEW ENEMY~~~~~~~~~~~\n";
    cout << "You Are facing Enemy #" << ENEMY_STAGE << endl;
    cout << "Name : " << paramPROFILE["Name"] << endl;
    cout << "Age  :" << paramPROFILE["Age"] << endl;
    cout << "STATS \n";
    cout << "Attack : " << paramSTATS["Attack"] << endl;
    cout << "Defense : " << paramSTATS["Defense"] << endl;
    cout << "Magic : " << paramSTATS["Magic"] << endl;
    cout << "Health : " << paramSTATS["Health"] << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    try
    {
        //This is where states Come Along
        cout << "What do you want to do? (A for Attack, D for defense, P for potion, F for flee)\n";
        std::cin >> STATE_CHOSEN_CIN;
        
        //Converting to UPPER_CASE, to reduce errors
        //on my part
        for(int i = 0; i < STATE_CHOSEN_CIN.size(); i++) 
            STATE_CHOSEN_CIN.at(i) = toupper(STATE_CHOSEN_CIN.at(i));
        
        if(STATE_CHOSEN_CIN.compare("A") == 0 || STATE_CHOSEN_CIN == "A")
        {
            __playerStates = PLAYER_STATES::ATTACK;
        }
                
                
        if(STATE_CHOSEN_CIN.compare("A") == 0 || STATE_CHOSEN_CIN == "A"
         ||STATE_CHOSEN_CIN.compare("D") == 0 || STATE_CHOSEN_CIN == "D"
         ||STATE_CHOSEN_CIN.compare("P") == 0 || STATE_CHOSEN_CIN == "P"
         ||STATE_CHOSEN_CIN.compare("F") == 0 || STATE_CHOSEN_CIN == "F")
         {
            //If he did press right chars, then
            //Assign the __playerStates, Enum Instance
            //to the diffrent types of the PLAYER_STATES
            //Types
            if(STATE_CHOSEN_CIN.compare("A") == 0 || STATE_CHOSEN_CIN == "A")
                __playerStates = PLAYER_STATES::ATTACK;
                
            else if(STATE_CHOSEN_CIN.compare("D") == 0 || STATE_CHOSEN_CIN  == "D")
                __playerStates = PLAYER_STATES::DEFENSE;
                
            else if(STATE_CHOSEN_CIN.compare("P") == 0 || STATE_CHOSEN_CIN  == "P")
                __playerStates = PLAYER_STATES::POTION;
                
            else
                __playerStates = PLAYER_STATES::FLEE;
                
            HandleStates(__playerStates);  

         }
        else
        {
                //User Has Chosen Another Letter...
                //Probably trying to break this code.
                cout << "Chose Wrong Char. Therfore Exiting\n";
                throw "Unsported Character";
        }
    }
    catch(const char* exc)
    {
        if(true)
            exit(1);
    }
}
void RPG::printChars(std::map<string,int> print)
{
    //Printing Stats at beggining of RPG.
    cout << "---------YOUR PLAYER STATS---------" << endl;
    cout << "Defense : " << print["Defense"] <<endl;
    cout << "Attack : " << print["Attack"] << endl;
    cout << "Magic : " << print["Magic"] <<endl;
    cout << "Health : " << print["Health"] << endl;
    cout << "-----------------------------------" << endl;
}

void RPG::initChar(Character &_char, string name, string age, string gender)
{
    //Initalizing Character. Function found
    //In Character.cpp
    _char.init(name,age,gender);
}

void RPG::HandleStates(PLAYER_STATES &_state)
{
    //Handling States, so i do some functinos
    //Foe either Attack, Defense, Potion or Flee
    switch(_state)
    {
        case PLAYER_STATES::ATTACK:
            cout << "You are in Attacking Stage\n";
                this -> attackModeState(_character.getStats(), _enemies[ENEMY_STAGE]);
            break;
        case PLAYER_STATES::DEFENSE:
            cout << "You are in Defense Stage \n";
            break;
        case PLAYER_STATES::POTION:
            cout << "You are in a Poition Stage\n";
            break;
        case PLAYER_STATES::FLEE:
            cout << "You are in Flee Stage\n";
            break;
        default:
            cout << "Something Happened....\n";
            exit(1);
            break;
    }   
}

void RPG::attackModeState(std::map<string,int> &statsParam, Enemy enemy)
{
        int ATTACK_AMT_INT_USER;
        int HEALTH_AMT_INT_USER;
        int DEFENSE_AMT_INT_USER;
        int DEFENSE_AMT_ENEMY_INT;
        int HEALTH_AMT_ENEMY_INT;
        int ATTACK_AMT_ENEMY_INT;
    while(true)
    {
        std::map<string, int> STATS = enemy._getStats();
         ATTACK_AMT_INT_USER   = statsParam["Attack"];
         HEALTH_AMT_INT_USER   = statsParam["Health"];
         DEFENSE_AMT_INT_USER  = statsParam["Defense"];
         DEFENSE_AMT_ENEMY_INT = STATS["Defense"];
         HEALTH_AMT_ENEMY_INT  = STATS["Health"];
         ATTACK_AMT_ENEMY_INT  = STATS["Attack"];
        
        //tan(75) --> 3.73...
        cout << "You deal a damage of " <<((HEALTH_AMT_ENEMY_INT - ATTACK_AMT_INT_USER) + DEFENSE_AMT_ENEMY_INT)<< endl;
        //Part of Update Process..
        enemy.decreaseHealth(((HEALTH_AMT_ENEMY_INT - ATTACK_AMT_INT_USER) + DEFENSE_AMT_ENEMY_INT) , HEALTH_AMT_ENEMY_INT);
        //z = cis(theta)  --->  z = rcos(theta) + irsin(theta) 
        enemy.decreaseDefense((DEFENSE_AMT_ENEMY_INT * 
                                                    ((10 * cos(30) + 10 * sin(30)) / 
                                                    (DEFENSE_AMT_ENEMY_INT / tan(75)) 
                                                    )
                              ) , DEFENSE_AMT_ENEMY_INT);
        //Update Enemy Stats..
        updateEnemies(STATS, enemy);
        
         ATTACK_AMT_INT_USER   = statsParam["Attack"];
         DEFENSE_AMT_ENEMY_INT = STATS["Defense"];
         HEALTH_AMT_ENEMY_INT  = STATS["Health"];
         
         if( HEALTH_AMT_ENEMY_INT <= 0 )
                break;
            
        cout << "Current Health Of Enemy " << STATS["Health"] << endl;
        cout << "Current Defense Of Enemy " << STATS["Defense"] << endl;
        
        cout << "ENEMY ATTACKS YOU! Attack : " << ((HEALTH_AMT_INT_USER - ATTACK_AMT_ENEMY_INT) + DEFENSE_AMT_INT_USER) <<  endl;
        statsParam["Health"] = ((HEALTH_AMT_INT_USER - ATTACK_AMT_ENEMY_INT) + DEFENSE_AMT_INT_USER);
        statsParam["Defense"] = (DEFENSE_AMT_INT_USER * 
                                                    ((10 * cos(30) + 10 * sin(30)) / 
                                                    (DEFENSE_AMT_INT_USER / tan(75)) 
                                                    )
                                );
        
         ATTACK_AMT_INT_USER   = statsParam["Attack"];
         HEALTH_AMT_INT_USER   = statsParam["Health"];
         DEFENSE_AMT_INT_USER  = statsParam["Defense"];
         
        cout << "You have Health : " << HEALTH_AMT_INT_USER << endl;
        cout << "You have Defense : " << DEFENSE_AMT_INT_USER << endl;
    }
    cout << "CONGRATULATIONS! You Defeated Enemy #" <<ENEMY_STAGE <<endl;
}

void RPG::continueState()
{
    string choice = "";
    try
    {
      cout << "Want to conintue?(Y or N . If otherwise, program will die) \n";   
      std::cin >> choice;
      if(choice.compare("Y") != 0 && choice.compare("N") != 0 && choice.compare("y") != 0
         && choice.compare("n") != 0)
        {
            cout << "Program died. You typed : " << choice << endl;
            throw "ProgramDied";
        }
      else
      {
          if(choice.compare("Y") == 0 || choice.compare("y") == 0)
          {
              cout << "Continuing to next enemy.... \n";
          }
          else
          {
              throw "Quit";
          }
      }
    }
    catch(const char * exc)
    {
        if(true)
            exit(1);
    }
}

RPG::~RPG()
{
}
