#include<iostream>

#define definedVar 4xx2342

int main(){
/*
#ifdef and #ifndef
checks if a "variable"
is defined. they are both opposite
one targetting if it is defined
and other if it is not.
Thats the only purpose of it
*/

///////////////////////////////
/////////// /////////// ///////
//List of Usefull Marcos

//#if, #elif, #else, #endif, #ifdef, #ifndef.
///////// ///////////  //////////
////////////////////////////////
#ifdef definedVar
 std::cout << "definedVar is defined" << std::endl;
#endif // definedVar

#ifndef notDefinedVar
 std::cout << "notDefinedVar is not Defined" << std::endl;
#endif // notDefinedVar
}
