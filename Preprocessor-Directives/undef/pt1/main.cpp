#include<iostream>

#define definedVar 4xx2342

int main(){
/*
#undef basically "undefines"
a defined variable.
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

#undef definedVar

#ifndef definedVar
 std::cout << "definedVar is not Defined" << std::endl;
#endif // definedVar
}
