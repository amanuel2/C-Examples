#include<vector>
#include "vector1.cpp"
#include "vector2.cpp"
int main() {
	std::vector<int> vectorOneVec;
	std::vector<int> vectorTwoVec;
	vectorOneVec.push_back(vectorOne::_X);
	vectorOneVec.push_back(vectorOne::_Y);

	vectorTwoVec.push_back(vectorTwo::_X);
	vectorTwoVec.push_back(vectorTwo::_Y);

	std::cout << "VECTOR 1" << std::endl << "X : " << vectorOneVec.at(0) << std::endl << "Y : " << vectorOneVec.at(vectorOneVec.at(1));
}
