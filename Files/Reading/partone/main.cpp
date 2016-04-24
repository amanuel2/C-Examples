#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::string line;
	std::ifstream _file_;
	_file_.open("mytext.txt");

	if (_file_.is_open()) {
		while (std::getline(_file_, line)) {
			std::cout << line << std::endl;
		}
		_file_.close();
	}
	else {
		try {
			while (std::getline(_file_, line)) {
				std::cout << line << std::endl;
			}
			_file_.close();
		}
		catch (std::exception const &exc) {
			throw exc;
			std::cout << "EXCEPTION!" << std::endl;
		}
	}

	std::cin.get();
}
