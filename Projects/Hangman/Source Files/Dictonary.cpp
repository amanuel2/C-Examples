#include<vector>
#include "../Header Files/Dictonary.h"

Dictonary::Dictonary()
{
       srand(time(NULL));
}

int myRand(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}

void Dictonary::init()
{
    string strArray[10] = {
        "RAM",
        "Registery",
        "Operating",
        "Memory",
        "CPU",
        "Proccecor",
        "Cpp",
        "Eat",
        "Code",
        "Sleep"
    };
    
    for(int i=0;i<=10;i++) 
        ITEMS.push_back(strArray[i]);
}
std::vector<string> Dictonary::getItems()
{
    return (ITEMS);
}

string Dictonary::randomItem()
{
  srand (time(NULL));
  randNum = myRand(0,10);
  
  if((ITEMS.at(randNum)).empty())
      this -> randomItem();
    
  return (ITEMS.at(randNum)); 
}


void Dictonary::addItems(std::vector<string> strArr)
{
    //UNDER CONSTRUCTION..
    //for(int i=0; i<= strings)
}

Dictonary::~Dictonary()
{
}
