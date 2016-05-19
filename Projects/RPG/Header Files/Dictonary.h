#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<map>

using std::cout;
using std::endl;
using std::string;


class Dictonary
{
public:


	Dictonary();
	~Dictonary();
	void init();
	string pickRandomItem();
private:
    std::vector<string> _names;
};
