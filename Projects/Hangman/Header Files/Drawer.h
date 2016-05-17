#pragma once
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;


class Drawer
{
public:

	Drawer();
	~Drawer();
    void drawHangMan(int attempts, int mode);
private:
};
