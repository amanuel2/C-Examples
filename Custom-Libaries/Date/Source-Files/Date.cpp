#include "Date.h"
#include <iostream>
#include <string>


Date::Date(int m, int d, int y)
	: date(d), month(m), year(y)
{

}

Date Date::operator+(Date sh) {
	Date brandNewDate(sh.month + month, sh.date + date, sh.year + year);
	return brandNewDate;
}

Date Date::operator-(Date sh) {
	Date brandNewDate(sh.month - month, sh.date - date, sh.year - year);
	return brandNewDate;
}


int Date::getMonth() {
	return month;
}
int Date::getDate() {
	return date;
}
int Date::getYear() {
	return year;
}
void Date::addDate(int dChange) {
	date = date + dChange;
}
void Date::addMonth(int mChange) {
	month = month + mChange;
}
void Date::addYear(int yChange) {
	year = year + yChange;
}
std::string Date::getFullDate() {
	std::string yearString = std::to_string(year);
	std::string monthString = std::to_string(month);
	std::string dateString = std::to_string(date);
	return (monthString + "/" + dateString + "/" + yearString);
}

Date::~Date()
{
}
