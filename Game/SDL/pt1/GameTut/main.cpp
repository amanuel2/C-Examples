#include<iostream>
#include"MainGame.h"

int main(int argc, char *argv[])
{
	int m;
	MainGame mg(650,500);
	mg.run();

	std::cout << "Enter Any Key To Quit";
	std::cin >> m;
	return 0;
}

