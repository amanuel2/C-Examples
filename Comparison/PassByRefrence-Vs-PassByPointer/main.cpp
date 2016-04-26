#include<iostream>
#include<string>

void passByAdress(int *a);
void passByRefrence(int &a);

int main() {
	int betty = 21;
	int setty = 45;

	passByAdress(&betty);
	passByRefrence(setty);

	std::cout << "Betty : " << betty << std::endl;
	std::cout << "Setty : " << setty << std::endl;
}

//Pass By Adress
void passByAdress(int *a) {
	*a = *a + 5;
	//Memory Adress of a.
	//So gives hexa decimal.
	std::cout << "Address : " << a << std::endl;
	//Actual Value of adress
	std::cout << "Adress's Value : " << *a << std::endl;
}
//Pass By Refrence
void passByRefrence(int &a) {
	a = a + 5;
	//Memory Adress of a.
	//So gives hexa decimal.
	std::cout << "Adress : " << &a << std::endl;
	//Actual Value of adress
	std::cout << "Adress's Value " << a << std::endl;
}
