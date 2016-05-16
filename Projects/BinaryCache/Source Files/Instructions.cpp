#include<vector>
#include "../Header Files/Instructions.h"

Instructions::Instructions()
{
}


void Instructions::printTableOfC()
{
    
    system("CLS");
    cout<<"\n\n\n\t\t\t\t~BinaryCACHE~";
        cout<<"\n\t\t\t\t  The Game (CACHE MEMORY!)";
        cout<<"\n\n\t\t\tPress the Enter Key to continue";
        getchar();
        cout<<"\n\nPlease Choose an Option:";
        cout<<"\n\n\t1.Start Game";
        cout<<"\n\t2.Help";
        cout<<"\n\t3.About";
        cout<<"\n\t4.Quit";
        cout<<"\n\n---(numeric value)---> ";
        cin>>swh;
        
        switch(swh){
            case 1:
                printGames();
                break;
            case 2:
                printHelp();
                break;
            case 3:
                printAbout();
                break;
            case 4:
                exit(1);
        }
}

void Instructions::printAbout()
{
	     cout<<" \n~~~~~ABOUT PAGE~~~~~";
                    cout<<"\n\nJust my first official game in C++...although its command line, it still somewhat fun! \nBy yours truly, Amanuel Bogale\nwhat else should I say...ah yes...\nDISClAIMER!!!\nThis game is not meant for people with blindness, people who cant read, people \nwho cant tell the difference between a number and a alphabet( infinte loop \nproblem ), and of course, Aliens, Beasts, and other inhuman mythical/fictional/\nimaginary/unreal/catostrophic/REAL Creatures of the deep/sky/beyond/and of \ncourse land...anything else...\n\nUm..... : reciprocal of 9.0252707581227436823104693140794e-4";
                    cout<<"\n\nDo you wish to go back to the main menu? ";
                    cout<<"\n---(Y or N)---> ";
                    cin>>aboutCheck;
    
        if(aboutCheck.compare("Y")){
            printTableOfC();
        } else if(aboutCheck.compare("y")){
            printTableOfC();
        }else{
            cout << "Ok I will Exit... " << endl;
            exit(1);
        }
        
}

void Instructions::printGames()
{
        cout<<" \n~~~~~GAMES PAGE~~~~~ ";    
        cout << "\n\n\t THERE ARE TWO GAMES AVAILABLE: \n";
        cout << "1) MasterMind (Ooooh Spoooookeh) \n" ;
        cout << "2) BinaryTime (Are you good at binary?) \n";
        cout << "\n Please select 1 or 2, or i will exit. Thanks for cooperating... \n";
        cin >> gameChoice;
        
        if(gameChoice == 1){
            gameChoiceEn = Games::MASTERMIND;
            mmdg.init();
        } else if(gameChoice == 2){
            gameChoiceEn = Games::BINARYTIME;
            bfdg.init();
        }else{
            exit(1);
        }
}

void Instructions::printHelp()
{
	    cout<<" \n~~~~~HELP PAGE~~~~~ ";
                    cout<<"\n\n\tSimply once you start the game, you must choose four numbers... \nThey MUST range from 0 through 9(Not really ;D). Please make sure you do not \ninput any letters or you will most likely get a infinte loop. Make sure you put spaces between each number. You must guess the random 4 numbers within 14 turns. Long enough right?Not quite so unless by luck or using algorithms. Good luck!!! :)";
                    cout<<"\n\nDo you wish to go back to the main menu? ";
                    cout<<"\n---(Y or N)---> ";
                    cin>>helpCheck;
                    
        if(helpCheck.compare("Y")){
            printTableOfC();
        } else if(helpCheck.compare("y")){
            printTableOfC();
        }else{
            cout << "Ok I will Exit... " << endl;
            exit(1);
        }
}

Instructions::~Instructions()
{
}
