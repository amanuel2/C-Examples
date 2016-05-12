#include "../Header Files/MainGraph.h"



MainGraph::MainGraph()
{
}

void MainGraph::draw()
{
	unsigned short COUNT = 0, COUNTTWO = 0;
	bool CHECK = true;
	for(int column=0; column<=10; column++){
		for(int row=0; row<=30; row++){
			if(COUNT == 0 || COUNT == 10 || COUNT == 3 || COUNT == 7)
				cout << "*";
			else{
				if(COUNTTWO == 0 || COUNTTWO == 8 || COUNTTWO == 22){
					cout << "*";
					COUNTTWO++;
				}else if(COUNTTWO == 30){
					cout << "*";
					COUNTTWO = 0;
				}
				else{
					cout << " ";
					COUNTTWO++;
				}
			}	
		}
		COUNT++;
		cout << endl;
	}
		
}

void MainGraph::drawX(int position, string charr)
{
	dp.drawP(charr,position);
}
MainGraph::~MainGraph()
{
}
