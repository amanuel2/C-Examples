#pragma once
#include<iostream>
#include <bitset>
#include<string>
#include<vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;


class Dictonary
{
public:

	Dictonary();
	~Dictonary();
	void init();
	std::vector<string> getItems();
    void addItems(std::vector<string> strArr);
    string randomItem();
private:
    int randNum;
    std::vector<string> ITEMS;
};
