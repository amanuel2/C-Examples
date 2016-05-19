#include<vector>
#include "../Header Files/Character.h"

Character::Character()
{
    srand(time(NULL));
}

int myRandStats(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}


void Character::init(string name,string age, string Gender)
{
    randomStatsGenerator(_stats);
    this -> setProfile(_profile,name,age,Gender);
}

std::map<string, int> Character::getStats(){
    //Getter for _stats MAP.
    return _stats;
}
std::map<string, string> Character::getProfile(){
    //Getter for _profile MAP.
    return _profile;
}

void Character::setProfile(std::map<string, string> &profileParam, string name, string age, string Gender)
{
    profileParam["name"] = name;
    profileParam["age"]  = age;
    profileParam["Gender"] = Gender;
}
void Character::randomStatsGenerator(std::map<string, int> &statsParam)
{
    //1) Attack,
    //2) Defense
    //3) Magic
    //4) Health
    string statTypes[4] = {
        "Attack", //0
        "Defense", //1
        "Magic", //2
        "Health" //3
    };
    
    //Adding in above string stats
    //To the MAP.
    for (int i = 0; i <= 3; i++) 
        statsParam[statTypes[i]] = myRandStats(30,100);
        
}

Character::~Character()
{
}
