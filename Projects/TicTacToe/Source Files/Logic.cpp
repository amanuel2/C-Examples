#include<vector>
#include "../Header Files/Logic.h"

Logic::Logic()
{

}

void Logic::run(std::vector<int> &avaiable, std::vector<int> &taken)
{
    short int posPlayer, posAI;
    string posPlayerStr;
    cout << "WHAT POSITON DO YOU CHOOSE? (0,9)" << std::endl;
    
    while(std::cin >> posPlayer)
    {
        returnPos(posAI,avaiable,taken);
        deleteVec(avaiable,taken,posPlayer,posAI);
        if(posPlayer <= 9 && posPlayer >= 0){
            mgraph.draw();
            mgraph.drawX(posPlayer,"X");
            mgraph.drawX(posAI,"O");
        	
        }else{
            try{
                if(true)
                    throw "UNEXPECTED POSITON";
            } catch(char const *error){
                exit(1);
            }
        }
    }
    
}

void Logic::drawSt(){
    
}
void Logic::returnPos(short int &posAI, std::vector<int> &avaiable, std::vector<int> &taken)
{
        
    unsigned short int COUNTVec = 0;
    srand( time( NULL ) );
    std::vector<int>::iterator it;
    for(it=avaiable.begin(); it!=avaiable.end(); it++)
        COUNTVec++;
        
      int num = (rand() % 8) + 0;    
      posAI = avaiable.at(num);
      std::cout << "AI NUM " << num << endl;
}

void Logic::deleteVec(std::vector<int> &avaiable, std::vector<int> &taken, short int posPlayer, short int posAI)
{
    taken.push_back(posPlayer);
    taken.push_back(posAI);
    
    avaiable.erase(avaiable.begin() + posAI);
    avaiable.erase(avaiable.begin() + posPlayer);
}

Logic::~Logic()
{
}
