
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>

/*
Author : Amanuel Bogale
Descripton: A Sprite to move in 4 directions
L
*/
//Defining Constant Variables
#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32
#define DIRECTION_Y_DOWN_INITAL 0
#define DIRETION_Y_LEFT_INITAL 1
#define DIRECTION_Y_RIGHT_INITAL 2
#define DIRECTION_Y_UP_INITAL 3

#define DIRECTION_X_DOWN_INITAL 0
#define DIRECTION_X_LEFT_INITAL 0
#define DIRECTION_X_RIGHT_INITAL 0
#define DIRECTION_X_UP_INITAL 0

#define TEXTURE_SIZE_X 96


using std::cout;
using std::endl;

//Mouvment Class for Sprite mouvment
class Mouvment
{
public:
	Mouvment() {};

	void goDirection(const int &dir, sf::Sprite &spritesheet)
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
	//Rendering To Window
	sf::RenderWindow _window(sf::VideoMode(600, 600), "Hello World");
	//Texture
	sf::Texture _texture;
	//Setting up the sources.
	sf::Vector2i source(DIRECTION_X_DOWN_INITAL, DIRECTION_Y_DOWN_INITAL);
	//Mouvment Chain
	Mouvment mouvment;
	//Error Checking _texture
	if (!(_texture.loadFromFile("Resources/SPRITE.png")))
	{
		cout << "Could Not Load File.." << endl;
	}
	//Create sprite with Texture.
	sf::Sprite _sprite;
	_sprite.setTexture(_texture);

	while (_window.isOpen())
	{
		//Event for event control
		sf::Event _event;
		while (_window.pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				_window.close();
				exit(1);
			case sf::Event::KeyPressed:
				switch (_event.key.code)
				{
				case sf::Keyboard::Right:
					//If Moved Right
					mouvment.goDirection(2, _sprite);
					source.x = DIRECTION_X_RIGHT_INITAL;
					source.y = DIRECTION_Y_RIGHT_INITAL;
					break;
				case sf::Keyboard::Left:
					//If Moved Left
					mouvment.goDirection(3, _sprite);
					source.x = DIRECTION_X_LEFT_INITAL;
					source.y = DIRETION_Y_LEFT_INITAL;
					break;
				case sf::Keyboard::Up:
					//If Moved Up
					mouvment.goDirection(0, _sprite);
					source.x = DIRECTION_X_UP_INITAL;
					source.y = DIRECTION_Y_UP_INITAL;
					break;
				case sf::Keyboard::Down:
					//If Moved Down
					mouvment.goDirection(1, _sprite);
					source.x = DIRECTION_X_DOWN_INITAL;
					source.y = DIRECTION_Y_DOWN_INITAL;
					break;
				}
				break;
			}
		}

		//You want to increase the x coordinates so you 
		//go thorugh all the columns, and repeat the procudere
		//UNTIL You reach the end of the sprite x.. When then you
		//Go back to 0. I explained it in stack like this:

		/*
		As you can see above, there are 3 sprites in a row... So _texture.getSize(); is 96 (32*3) WHere 32 is width of one sprite char.
		Source.x increases by 1 REALY FAST, and once it gets to the max size of the texture it has to go back to its orignal state..
		This explanation translates to the code below.
		*/
		source.x++;
		if (source.x * 32 >= TEXTURE_SIZE_X)
			source.x = 0;


		//Basically here im cropping out the image
		//To udnerstand it better lets take a look at this example
		//_sprite.setTextureRect(sf::IntRect(0,0 , SPRITE_WIDTH, SPRITE_HEIGHT));
		//Ok here we do 0,0 for our x coordinate to crop out and 0 for our y to crop
		//out.. Basically the first figure (Top RIGHT Corner of Sprite in Resources/SPRITE.png)
		//starts out with 0, bieng the x right most of the first sprite char, and y the downmost
		//of the first sprite char.. So basically it just crops the first sprite char out.
		//Then next you can just play around with it knowing one sprite is 32 in x size and y size.
		//Lastly we just give the width and height of one sprite char.
		
		_sprite.setTextureRect(sf::IntRect(source.x * SPRITE_WIDTH , source.y * SPRITE_HEIGHT , SPRITE_WIDTH, SPRITE_HEIGHT));
		_window.draw(_sprite);
		_window.display();
		_window.clear();
	}
}
