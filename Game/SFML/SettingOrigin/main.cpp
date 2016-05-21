#include<iostream>
#include<string>
#include<SFML\Graphics.hpp>

using std::cout;
using std::endl;

int main()
{
	sf::RenderWindow _Win(sf::VideoMode(600, 600), "Hello World");
	//Texture. Basically Image.
	sf::Texture _TEXTURE;

	if (!(_TEXTURE.loadFromFile("Resources/PaddleLarge.png")))
	{
		//Error Checking
		cout << "Error Loading Image" << endl;
	}

	//Sprite. Takes Image.
	sf::Sprite _SPRITE;
	_SPRITE.setTexture(_TEXTURE);

	//Setting Color of Sprite to RED.
	_SPRITE.setColor(sf::Color(255,0,255));

	//_Win.getSize().x;
	//_Win.getSize().y;
	//Set SPRITE Origin
	_SPRITE.setOrigin(sf::Vector2f(-150, -250)); 
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
		//Clears Window(Flickering..)
		_Win.clear();
		//Draws The Sprite To Window..
		_Win.draw(_SPRITE);
		//And Finally Display the Window.
		_Win.display();
	}
}
