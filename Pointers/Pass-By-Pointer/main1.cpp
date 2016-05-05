#include <iostream>
#include <string>
const int NUM = 5;

template<class T>
void add(T *num, T addNum){
    *num += addNum;
}

int main()
{
   double numToAddDouble = 3.1232131;
   double adderDoub = 6.434343;
    std::cout << numToAddDouble << std::endl;
    //3.1232131
   add(&numToAddDouble, adderDoub);
    std::cout << numToAddDouble << std::endl;
    //9.557...

    int numToAddInt = 3;
    int adderInt = 6;
    std::cout << numToAddInt << std::endl;
    //3
   add(&numToAddInt, adderInt);
    std::cout << numToAddInt << std::endl;
    //9 ...

    std::string strToAdd = "Hello ";
    std::string adderString = "World";

    std::cout << strToAdd << std::endl;
    //Hello ..
   add(&strToAdd, adderString);
    std::cout << strToAdd << std::endl;
    //Hello World...
}

