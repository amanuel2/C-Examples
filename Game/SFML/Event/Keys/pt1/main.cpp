#include<iostream>
#include <SFML/Graphics.hpp>
#include<windows.h>

using std::cout;
using std::endl;
int main()
{
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
                cout << "Key Pressed..." << endl;
                break;
            }
      }

    }
}
