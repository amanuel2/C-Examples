#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<map>

using std::cout;
using std::endl;
using std::string;


class Character
{
public:


	Character();
	~Character();
	void init(string name, string age, string Gender);
	std::map<string, int> getStats();
	std::map<string, string> getProfile();

private:
//1) Attack,
//2) Defense
//4) Magic
//3) Health
	std::map<string, int> _stats;

//1)Name
//2)Age
//3)Gender
    std::map<string, string> _profile;
    
    void randomStatsGenerator(std::map<string, int> &stats);
    void setProfile(std::map<string, string> &profileParam, string name, string age, string Gender);
};
