#include "Sprite.h"
#include<GL/glew.h>


Sprite::Sprite()
{
	_vboID = 0;
}

void Sprite::init(float x, float y, float width, float height)  {
	_x = x;
	_y = (y);
	_width = (width);
	_height = (height);
	if (_vboID == 0) {
		glGenBuffers(1, &_vboID);
	}
	//6 * 2 ... 6 Vertex For Square 
	float vertexData[12];

	 vertexData[0] = _x + _width;
	vertexData[1] = _y + _height;

	vertexData[2] = _x;
	vertexData[3] = _y + _height;

	vertexData[4] = _x;
	vertexData[5] = _y;

	//Second Triangle
	vertexData[6] = _x;
	vertexData[7] = _y;

	vertexData[8] = _x + _width;
	vertexData[9] = _y;

	vertexData[10] = _x + _width;
	vertexData[11] = _y + _height;
	//Bind Buffer..
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);
	//Upload Buffer..
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	//Just Enables Positioning..
	glEnableVertexAttribArray(0);

	//This is were you draw
	glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,0);


	glDrawArrays(GL_TRIANGLES,0,6);

	glDisableVertexAttribArray(0);


	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Sprite::~Sprite()
{
}
