#include <iostream>
#include <string>

template <class T>
class TypeFinder {
public:
	TypeFinder(T a) {
		std::cout << "Of Type : " << typeid(a).name() << std::endl;
	}
};

template <>
class TypeFinder <char>{
public:
	TypeFinder(char) {
		std::cout << "Of Type Char " << std::endl;
	}
};
int main() {
	TypeFinder<char> cha1('A');
	TypeFinder<int> cha2(23);
	TypeFinder<float> cha3(2.12);
}
