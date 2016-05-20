#include<iostream>
#include <SFML/Graphics.hpp>
#include<windows.h>
#include<vector>
#include<bitset>
#include <sstream>

using std::cout;
using std::endl;

class BinaryGame
{
public:
    BinaryGame()
    {

    };
    void pushToBin(const std::string &binNum)
    {
            binaryTyped.push_back(binNum);
    }

    void convertToStr()
    {
        for(std::vector<std::string>::iterator it=binaryTyped.begin(); it!=binaryTyped.end(); it++)
        {
            std::string itStr;
            std::stringstream ss;
            ss << (*it);
            ss >> itStr;
            binTypedStr = binTypedStr + itStr;
        }
    }

    void tellBinary()
    {
            std::bitset<10>  bin(binTypedStr);
            cout << "\n Decimal : " << binTypedStr << endl;
            cout << " Binary : " << bin.to_ulong() << endl;
    }

    void enterRun()
    {
        this->convertToStr();
        this->tellBinary();
    }
private:
     std::vector<std::string> binaryTyped;
     std::string binTypedStr;
};
int main()
{
    BinaryGame bg;
    sf::RenderWindow _WINDOW(sf::VideoMode(600,600), "HELLO WORLD");

    while(_WINDOW.isOpen() )
    {
      sf::Event _EVENT;
      while(_WINDOW.pollEvent(_EVENT))
      {
          switch(_EVENT.type)
          {
          case sf::Event::Closed:
                _WINDOW.close();
                Sleep(3);
                exit(1);
                break;
          case sf::Event::KeyPressed:
                switch(_EVENT.key.code)
                {
                case sf::Keyboard::Num0:
                        cout << "0";
                        bg.pushToBin("0");
                        break;
                 case sf::Keyboard::Num1:
                        cout << "1";
                        bg.pushToBin("1");
                        break;
                 case sf::Keyboard::Return:
                        bg.enterRun();
                }
            }
      }

    }
}
