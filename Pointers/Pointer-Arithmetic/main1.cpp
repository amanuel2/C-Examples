#include <iostream>
#include <string>
const int NUM = 5;

int main()
{
    std::string names[NUM] = {"First", "second", "third", "fouth" , "ffith"};
    std::string *namesPtr = names;

    std::cout << *namesPtr << std::endl;

    namesPtr += 3;

    std::cout << *namesPtr << std::endl;

}
