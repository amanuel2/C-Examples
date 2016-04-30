#pragma once
class Sprite
{
public:
	Sprite(  );
	~Sprite();
	void init(float x, float y, float width, float height );
	void draw( );

private:
	float _width, _height, _x, _y;
	//Gluint -> unsigned int + Must 32BIT .
	unsigned int _vboID;
};

