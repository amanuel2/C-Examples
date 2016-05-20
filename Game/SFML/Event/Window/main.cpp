#include<iostream>
#include <SFML/Graphics.hpp>
#include<windows.h>
#include<vector>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow _WINDOW(sf::VideoMode(600,600), "HELLO WORLD");

    while(_WINDOW.isOpen() )
    {
      sf::Event event;
      while(_WINDOW.pollEvent(event))
      {
        switch (event.type)
			{
			case sf::Event::Closed:
				_WINDOW.close();

				break;

			case sf::Event::Resized:
				std::cout << event.size.width << " : " << event.size.height << std::endl;

				break;

			case sf::Event::LostFocus:
				std::cout << "Lost Focus" << std::endl;

				break;

			case sf::Event::GainedFocus:
				std::cout << "Gained focus" << std::endl;

				break;
			}
            _WINDOW.clear( );
            _WINDOW.display( );
      }

    }
}
