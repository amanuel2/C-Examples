#include <iostream>
#include <string>

class Integer {
public:
	Integer() {
		inptr = new int;
		count++;
	}
	Integer( int i ) {
		inptr = new int; 
		*inptr = i;
		count++;
	}
	void setValue( int i ) {
		*inptr = i;
	}
	int getValue() { return *inptr; }

	static int getCount() {
		return count;
	}
private:
	int* inptr;
	static int count;
};

int Integer::count = 0;

int main() {

	std::cout << "There are " << Integer::getCount() << " Count.." << std::endl;
	Integer i, j(10);
	i.setValue(3);
	std::cout << "Value : " << i.getValue() << std::endl;
	std::cout << "Value : " << j.getValue() << std::endl;
	std::cout << "There are " << Integer::getCount() << " Count.." << std::endl;
}
