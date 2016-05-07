#include<iostream>

#define definedVar 4xx2342
/**
  * @param C++E
  * @authr Amanuel Bogale
  */
int main(){
/*
Predefined Marcos:
_LINE_  = identifies current line
_FILE_  = identifies current working directory
_DATE_  = identifies current date
_TIME_  = identfies current time
_STDC_  = checks if it is standard c++ Code
*/

///////////////////////////////
/////////// /////////// ///////
//List of Usefull Marcos
//#if, #elif, #else, #endif, #ifdef, #ifndef.
///////// ///////////  //////////
////////////////////////////////

std::cout << "CURRENT LINE " << __LINE__ << std::endl;
std::cout << "CURRENT FILE DIR : " << __FILE__ << std::endl;
std::cout << "CURRENT DATE : " << __DATE__ <<std::endl;
std::cout << "CURRENT TIME : " << __TIME__ <<std::endl;
std::cout << "Standard C++ CODE? " << __STDC__ << std::endl;

/*
CURRENT LINE 25
CURRENT FILE DIR : C:\[SECRET FOLDER]\[SECRET NAME]\C++Projects\PreProccecor\main.cpp
CURRENT DATE : May  7 2016
CURRENT TIME : 18:47:30
Standard C++ CODE? 1

Process returned 0 (0x0)   execution time : 0.605 s
Press any key to continue.
*/


}
