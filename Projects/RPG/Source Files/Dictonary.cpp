#include<vector>
#include "../Header Files/Dictonary.h"

Dictonary::Dictonary()
{
    srand(time(NULL));
}

int myRandStatsD(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}

void Dictonary::init()
{
    string names[18] = {"Aaren","Aarika","Abagael","Abagail","Abbe","Abbey","Abbi",
                      "Abbie","Abby","Abbye","Ada","Illa","Ilsa","Ilse","Ilysa",
                      "Ilyse","Ilyssa","Imelda"};
                      
    for(int i =0; i< 18; i++)
        _names.push_back(names[i]);
}

string Dictonary::pickRandomItem()
{
    if(_names.size() == 0)
        this -> init();
    else
        return _names.at(myRandStatsD(0,17));
}

Dictonary::~Dictonary()
{
}
