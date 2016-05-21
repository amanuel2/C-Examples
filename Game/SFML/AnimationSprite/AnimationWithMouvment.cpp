
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

class Mouvment
{
public:
	Mouvment(){};
	
	void direction(const int &dir, sf::Sprite &spritesheet)
	{
		switch (dir) {
		case 0:
			spritesheet.move(sf::Vector2f(0, -3));
			break;
		case 1:
			spritesheet.move(sf::Vector2f(0, 3));
			break;
		case 2:
			spritesheet.move(sf::Vector2f(3, 0));
			break;
		case 3:
			spritesheet.move(sf::Vector2f(-3, 0));
			break;
		}
	}
};
int main()
{
	enum Direction { Down, Left, Right, Up };
	sf::Vector2i source(32, Down);
	Mouvment mouvment;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "Tuto SFML");

	sf::Texture ss;
	if (!ss.loadFromFile("Resources/SPRITE.png")) // YOUR SPRITE PATH
	{
		return EXIT_FAILURE;
	}
	sf::Sprite spritesheet;
	spritesheet.setTexture(ss);
	sf::Clock clock;
	float x = 3, y = 3;
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (sf::Event::KeyPressed)
			{
				if (Event.key.code == sf::Keyboard::Up)
				{
					source.y = Up;
					(mouvment.direction(0, spritesheet));
				}
				if (Event.key.code == sf::Keyboard::Down)
				{
					source.y = Down;
					(mouvment.direction(1, spritesheet));
				}
				if (Event.key.code == sf::Keyboard::Left)
				{
					source.y = Left;
					(mouvment.direction(3, spritesheet));
				}
				if (Event.key.code == sf::Keyboard::Right)
				{
					source.y = Right;
					(mouvment.direction(2, spritesheet));
				}
			}

		}


			source.x++;
			if (source.x * 32 >= ss.getSize().x)
				source.x = 0;
			clock.restart();


		spritesheet.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
		window.draw(spritesheet);
		window.display();
		window.clear();
	}

	return EXIT_SUCCESS;
}
