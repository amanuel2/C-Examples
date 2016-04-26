#pragma once
#include<string>
class Date
{
public:
	Date(int m, int d, int y);
	~Date();
	int getMonth(); 
	int getYear(); 
	int getDate(); 
	void addDate(int dChange); 
	void addYear(int yChange);
	void addMonth(int mChange);
	std::string getFullDate();
	Date operator+(Date);
	Date operator-(Date);
	//Could continue on with operators
	//But would be unusual to divide/multiply
	//date.. Unnececary Memory Usage.


private:
	int date, month, year;
};

