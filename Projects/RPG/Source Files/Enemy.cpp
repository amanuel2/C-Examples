#include<vector>
#include "../Header Files/Enemy.h"

Enemy::Enemy()
{
    srand(time(NULL));
}

int myRandStatsE(int low, int high) 
{
   return rand() % (high - low + 1) + low;
}


void Enemy::init()
{
 this -> initProfile();
 this -> initStats();
}
void Enemy::initProfile()
{
    string randomName;
    _dict.init();
    randomName =  _dict.pickRandomItem();
    int intAge = myRandStats(10,100);
    std::string ageString = std::to_string(intAge);
    _profile["Name"] = (randomName);
    _profile["Age"] = (ageString);
}
void Enemy::initStats()
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
        _stats[statTypes[i]] = myRandStatsE(30,100);
}

void Enemy::decreaseHealth(int amount, int previousAmount)
{
    _stats["Health"] = previousAmount - amount;
}

void Enemy::decreaseDefense(int amount, int previousAmount)
{
    _stats["Defense"] = previousAmount - amount;
}

std::map<string, int> Enemy::_getStats()
{
    return _stats;
}
std::map<string, string> Enemy::_getProfile()
{
    return _profile;
}

Enemy::~Enemy()
{
}
