#include<iostream>
#include<string>
#include<SFML\Graphics.hpp>

using std::cout;
using std::endl;

int main()
{
	sf::RenderWindow _Win(sf::VideoMode(600, 600), "Hello World");
	cout << "Working.. " << endl;

	while (true)
	{
		sf::Event _event;
		while (_Win.pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				_Win.close();
				exit(1);
				break;
			}
		}

		/**
		** Basically This Function
		** Provides a Very Fast Way
		** (Faster than above) of checking
		** Key Pressed... Mostly Used in 
		** Animations...(Catius : This Is Very Fast)
		** Like a VERY Fast Tap On Press of a mouse button
		** Would result on average the if statement
		** to be called 5 times... This is dangerously
		** fast.[Basically The Same As Keyboard.. This is
		** just on the mouse]
		*/

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			cout << "Left Mouse Pressed" << endl;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			cout << "Right Mouse Pressed" << endl;
		}
	}
}
