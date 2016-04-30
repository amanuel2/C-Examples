#pragma once
#include<Windows.h>
#include<SDL.h>
#include<GL/glew.h>
#include<string>
class Sprite
{
public:
	Sprite();
	~Sprite();
	void init(float y, float x, float width, float height);
	void draw();
private:
	float _x, _y, _width, _height;
	//Gluint = unsigned int + Must Be 32BIT;
	GLuint _vboId;
};

