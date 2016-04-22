#include <iostream>
#include <string>

/**
 **TODO:
 */
template <class rate>
class Developers {


public:
	Developers(std::string type_, rate rating_) {
		type = type_; rating = rating_;
	}
	rate evaluate();

protected:
	std::string type;
	rate rating;
};

template<class rate>

rate Developers<rate>::evaluate() {
	rate points;
	if (type.compare(".NET Developer") == 0) {
		points = rating + 3;
	}
	else if (type.compare("Android Developer") == 0) {
		points = rating + 2;
	}
	else if (type.compare("Front End Developer") == 0) {
		points = rating + 2;
	}
	else {
		points = rating + 1;
	}

		return points;
}
int main() {
	Developers<double> sens("Front End Developer" , 99);
	std::cout << sens.evaluate() << std::endl;

	Developers<float> amanuel(".NET Developer", 50);
	std::cout << amanuel.evaluate() << std::endl;
}

