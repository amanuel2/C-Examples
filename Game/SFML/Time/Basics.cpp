#include<iostream>
#include<string>
#include<SFML\Graphics.hpp>

using std::cout;
using std::endl;

//Custom Class to fill in
//a nanosecond for sf::time
class nanoSecondSMFL
{
public:
	nanoSecondSMFL():_nanoSecond(0) {};
	nanoSecondSMFL(sf::Int64 _nano):_nanoSecond(_nano) {};
	sf::Int64 asNanoSeconds()
	{
		return (_nanoSecond);
	}
	sf::Int64 asMicroSeconds()
	{
		return (_nanoSecond / 1000);
	}
	sf::Int64 asMilliSeconds()
	{
		return (_nanoSecond / 1000000);
	}
	sf::Int64 asSeconds()
	{
		return (_nanoSecond / 1000000000);
	}
	void Zero() { _nanoSecond = 0; }
	void setNanoSecond(const sf::Int64& _time) 
	{
		_nanoSecond = _time; 
	}
private:
	sf::Int64 _nanoSecond;
};
int main()
{
	sf::RenderWindow _Win(sf::VideoMode(600, 600), "Hello World");
	//SFML CLOCK
	sf::Clock clock;
	//SFML Time
	//1000 nanoseconds -> 1 microseconds.
	nanoSecondSMFL time(1000);
	//1000 microseconds -> 1 millisecond
	sf::Time time1 = sf::microseconds(1000);
	//1000 milliseconds -> 1 second
	sf::Time time2 = sf::milliseconds(1000);

	sf::Time tmie3;


	while (true)
	{
		sf::Event _event;
		while (_Win.pollEvent(_event))
		{
			switch (_event.type)
			{
			case sf::Event::Closed:
				//Get Elapsed Time
				tmie3 = clock.getElapsedTime();
				//Cout it as a second
				cout << "You Elapsed " << tmie3.asSeconds() << "Seconds" << endl;
				_Win.close();
				exit(1);
				break;
			}
		}
		//Clears Window(Flickering..)
		_Win.clear();
		//And Finally Display the Window.
		_Win.display();
	}
}
