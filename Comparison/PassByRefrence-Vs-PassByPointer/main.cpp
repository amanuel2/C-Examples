#include<iostream>
#include<string>

void passByAddress(int *a);
void passByReference(int &a);

int main() {
    int betty = 21;
    int setty = 45;

    passByAddress(&betty);
    passByReference(setty);

    std::cout << "Betty : " << betty << std::endl;
    std::cout << "Setty : " << setty << std::endl;
}

//Pass By Adress
void passByAdrress(int *a) {
    *a = *a + 5;
    //Memory Adress of a.
    //So gives hexa decimal.
    std::cout << "Address : " << a << std::endl;
    //Actual Value of adress
    std::cout << "Address's Value : " << *a << std::endl;
}
//Pass By Reference
void passByReference(int &a) {
    a = a + 5;
    //Memory Address of a.
    //So gives hexa decimal.
    std::cout << "Adrress : " << &a << std::endl;
    //Actual Value of address
    std::cout << "Address's Value " << a << std::endl;
}
