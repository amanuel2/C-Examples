#include<iostream>
#include<string>
#include<fstream>

int main() {
	int ID;
	std::string NAME;
	double MONEY;
	std::ofstream sampleFile("players.txt");

	std::cout << "Enter Players Name, ID, and Money" << std::endl;
	std::cout << "Press Ctrl+Z To Quit" << std::endl;
	while (std::cin >> (ID) >> (NAME) >> (MONEY)) {
		sampleFile << ID << " " << NAME << " " << MONEY << std::endl;
	}
}
//Players.txt is displayed in this directory in github.
