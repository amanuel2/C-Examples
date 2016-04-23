#include <iostream>
#include <string>
#include <fstream>

int main() {

	std::ofstream _file_;
	_file_.open("mytext.txt");
	std::string Strings[3] = { "first","second","third" };
	if (_file_.is_open()) {
		for (int i = 0; i <= 2; i++) {
			_file_ << "This is my " + Strings[i] + " line \n";
		}
		_file_.close();
	}
	else {
		try {
			for (int i = 0; i <= 2; i++) {
				_file_ << "This is my " + Strings[i] + " line \n";
			}
			_file_.close();
		}catch(std::exception const &exc){
			throw exc;
			std::cout << "EXCEPTION!" << std::endl;
		}
	}

	std::cin.get();
}
