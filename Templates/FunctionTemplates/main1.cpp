#include <iostream>
#include <string>


/**
**IMPORTANT: dataType DataTypes 
** CANNOT BE DIFFRENT DATATYPES.
*/
template <class dataType>
dataType add(dataType dt1, dataType dt2) {
	return (dt1 + dt2);
}
int main() {
	double x = 3.342424;
	double y = 4.343424;
	std::cout << add(x, y) << std::endl;

	int xInt = 3;
	int yInt = 3;
	std::cout << add(xInt, yInt) << std::endl;

	std::string xString = "Hello";
	std::string yString = " World";
	std::cout << add(xString, yString) << std::endl;

	long xLong = 3232323;
	long yLong = 24242422;
	std::cout << add(xLong, yLong) << std::endl;

	float xFloat = 3.32323232;
	float yFloat = 5.343434343;
	std::cout << add(xFloat, yFloat) << std::endl;
}
