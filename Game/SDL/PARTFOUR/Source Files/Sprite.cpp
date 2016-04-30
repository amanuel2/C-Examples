#include "Sprite.h"
#include<GL/glew.h>

Sprite::Sprite() {
	_vboId = 0;
}
Sprite::~Sprite()
{
	/*When Sprite Deleted,
	*Delete Buffer, so you
	*Can Free Space. You already
	*Send this Data, to the
	*GPU(Graphical Proccesor Unit)
	*So no need to send it again, as
	*it can just draw it(because it has info/vertexData)
	*/

	//First Check if Virtual Buffer Object
	if (_vboId != 0) {
		//Oppisite of glGenBuffers... 
		//one generates, this deletes.
		//No Need to store it since, its already stored in GPU,
		//when we initalized;
		glDeleteBuffers(1, &_vboId);
	}

}
void Sprite::init(float y, float x, float width, float height) {
	_x = x; _y = y; _width = width; _height = height;

	//Only generate buffer if it hasnt already been so..

	if (_vboId == 0) {
		/*Virtual Buffer Object bieng
		Alocated to Virtual Buffer ID.
		1 Virtual Buffer Object..
		Returns a virtual buffer object, so
		must pass a pointer to our _vboId
		to a Virtual Buffer Object*/
		glGenBuffers(1, &_vboId);
	}

	//Vertext Data for square. Two Triangles
	// Draw x, and y coordinates for each 6 vertices
	//First Triangle..

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

	//Activate Buffer.. 
	//In Our Case a Array Buffer of floats
	glBindBuffer(GL_ARRAY_BUFFER, _vboId);
	//Upload the Data to our Vertext Buffer Object
	//Array Buffer, Size of array in bits, pointer to array
	// And How many times to draw it.
	//Arrays can be pointers, and also pointers can be arrays..
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);


	//Unbind Buffer to make it more secure
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {
	/*Once Vertex Data has been sent to
	*the GPU(Graphical Proccesor Unit)
	*It has info, so it can draw as many
	*times needed. No Need to pass a vertext
	*at a time.. This is safe memory usage,
	*and Increase of speed. Tells OpenGL Current
	*Buffer Active
	*/
	glBindBuffer(GL_ARRAY_BUFFER, _vboId);

	/*
	*Give OpenGL Attributes to use. For now its
	*Only Position. Its possible to give it color
	*, lighining as i will show later.
	*Now we are sending one vertext attribute array
	*that is our vertexData that holds the positions
	*of the Square.
	*/
	glEnableVertexAttribArray(0);

	//Have to let OpenGL Know where
	//Vertex Data is.

	//Attributes Given to function
	// 0 (because we enabled only position above ^^)
	// 2 (Size of each cordinate. (since we are doing x,y(2D) then we pass in 2) )
	// GL_FLOAT (because we are using float arrays for our vertex Data..)
	// GL_FALSE (not normalized. Later Lesson Explaining why not)
	// 0 (stride.. Later Lesson Explaining why)
	// 0 (Later Lesson Explaining why)
	/*
	*This tells where Data is/How you should draw the image you recieved from CPU.
	*(as we did in init function)
	* We put in 2 because its x,and y coordinates
	*/
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);


	//Now Drawing
	//0 , since position 0 is our first data.
	//and 6 vertices
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//Disable Vertex Attrib Array..
	glDisableVertexAttribArray(0);

	//Unbind Buffer to make it more secure
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}




