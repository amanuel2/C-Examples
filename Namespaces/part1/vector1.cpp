#include<iostream>
#include<string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



namespace vectorOne {
	
	int randNumber(int *rChange, int min, int max) {
		srand(time(NULL));
		int poll = rand() % (max + 1) + min; // random number between 0 and 19 inclusive
		*rChange = poll;
		return 0;
	}
	 int _X, _Y;
	void setNumbers() {
		_X = randNumber(&_X, 0, 10);
		_Y = randNumber(&_Y, 0, 10);
	}
}
