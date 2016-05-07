/*
Simple Ilustration of #if #elif and #else
Author : Amanuel Bogale
*/

#include<iostream>

#define WINDOWS 1
#define LINUX 0
#define MAC 1

#define OS Windows

///////////////////////////////
/////////// /////////// ///////
//List of Usefull Marcos

//#if, #elif, #else, #endif, #ifdef, #ifndef.
///////// ///////////  //////////
////////////////////////////////

int main(){

#if OS == Windows
 std::cout << "OS IS WINDOWS";

#elif OS == LINUX
   std::cout << "LINUX";
 #else
   std::cout << "SDSD";

#endif // OS
std::cout << "DFS" << std::endl;
}
