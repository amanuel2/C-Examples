#include<iostream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template<class T>
class Randomizer {
public:
	Randomizer(T num1, T num2):_NUM1(num1), _NUM2(num2){}
	T getRandom();
private:
	T _NUM1, _NUM2;
};

template<class T>
T Randomizer<T>::getRandom() {
	srand(time(NULL));
	return(rand() % _NUM1 + _NUM2);
}

int main() {
	/*Randomizer Code:
	**Question : <http://stackoverflow.com/questions/37092913/if-vs-ifndef-vs-ifdef?noredirect=1>
	**1 = πάντα ῥεῖ
	**10 = tobi303*/
	std::string str;
	std::string winner;



	Randomizer<long> randomCode(1, 10);
	long randomNumber = randomCode.getRandom();
	std::cout << "RANDOM NUMBER" << randomNumber << std::endl;
	switch (randomNumber) {
		case 1:
			winner = "πάντα ῥεῖ";
			std::cout << "WINNER IS " << winner;

			break;
		case 10:
			winner = "tobi303";
			std::cout << "WINNER IS " << winner;
			break;

		default:
			if (randomNumber > 5) {
				winner = "πάντα ῥεῖ";
				std::cout << "WINNER IS " << winner;
			}
			else {
				winner = "tobi303";
				std::cout << "WINNER IS " << winner;
			}
	}
    std::cin >> str;
}
/*RESULTS:
1 : tobi
2 : tobi
3 : tobi
*/
