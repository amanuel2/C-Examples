/**
*Simple #define marco usage
*in C++
*/

#include<iostream>
#include<string>

#define MAC 0001001;
#define LINUX  11101101;
#define WIN 100010001;
#define findMAX(num,num2) ( num > num2 ? ( num ) : ( num2 ) );



int main() {
	std::string str;
	long OS = MAC;
	long OS2 = LINUX;
	std::cout << OS << std::endl;
	std::cout << findMAX(OS, OS2);
    std::cin >> str;
}
