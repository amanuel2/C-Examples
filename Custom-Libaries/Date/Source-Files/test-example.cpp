#include<iostream>
#include <string>
#include "Date.h"


int main() {
	Date newDate(12,23,2016);
	std::string newDateFullString =  newDate.getFullDate();
	std::cout << newDateFullString << std::endl;
	newDate.addDate(5);
	newDate.addMonth(3);
	newDate.addYear(1);
	std::string newDateFullStringTwo = newDate.getFullDate();
	std::cout << newDateFullStringTwo << std::endl;

	Date anotherDate(12, 29, 2000);
	Date addedDate = anotherDate + newDate;
	std::cout << addedDate.getFullDate() << std::endl;

	Date subtractedDate =  anotherDate - newDate;
	std::cout << subtractedDate.getFullDate() << std::endl;
}
