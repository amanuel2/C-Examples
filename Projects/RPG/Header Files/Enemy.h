#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<map>
#include "../Source Files/Dictonary.cpp"

using std::cout;
using std::endl;
using std::string;


class Enemy
{
public:


	Enemy();
	~Enemy();
    void init();
    std::map<string, int> _getStats();
    std::map<string, string> _getProfile();
    void decreaseHealth(int amount, int previousAmount);
    void decreaseDefense(int amount, int previousAmount);
private:
	Dictonary _dict;
//1) Attack,
//2) Defense
//4) Magic
//3) Health
	std::map<string, int> _stats;
	
//1)Name
//2)Age
    std::map<string, string> _profile;
    
    void initProfile();
    void initStats();
    
};
