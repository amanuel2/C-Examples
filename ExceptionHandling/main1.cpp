#include <iostream>
#include <string>
#include <bitset>

long intLength(long i)
{
	int l = 0;
	for (; i; i /= 10) l++;
	return l == 0 ? 1 : l;
}


std::string convertToString(long num) {
	try {
		if (intLength(num) > 15) {
			throw "Number To Big!";
		}
		else {
			return std::bitset<8>(num).to_string();
		}
	}
	catch (std::string numberToLargeException) {
	//numberToLargeException is self made exception..
		std::cout << numberToLargeException << std::endl;
	}
}

int main() {
	long input;
	std::cout << "Number to convert into string.." << std::endl;
	std::cin >> input;
	std::cout << "Convertion of " << input << " to string : " 
				<< convertToString(input) << std::endl;
}
