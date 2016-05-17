#include<vector>
#include "../Header Files/Drawer.h"

Drawer::Drawer()
{
}

void Drawer::drawHangMan(int attempts, int mode)
{
		//attempts = wrong attempts 
		/*
		___________
		|         |
		|        \O/
		|		  |
		|		  |
		|		 / \
		|______________________
		*/
		if (mode == 0){
			/*Easy mode - 10 */

			if (attempts == 0){
				return;
			}
			else if (attempts == 1){
				//Bottom stand
				cout << " ______________________" << endl;
			}
			else if (attempts == 2){
				//Left part of hang
				cout << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 3){
				//Entire hang
				cout << "___________" << endl << "|         |" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;

			}
			else if (attempts == 4){
				//Head
				cout << "___________" << endl << "|         |" << endl << "|         O" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 5){
				//Left arm, head
				cout << "___________" << endl << "|         |" << endl << "|        \\O" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 6){
				//Left arm, head, right arm
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 7){
				//Left arm, head, right arm, half of body
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 8){
				//Left arm, head, right arm, full body
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|         |" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 9){
				//Left arm, head, right arm, full body, left leg
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|         |" << endl << "|	 / " << endl << "|______________________" << endl;
			}
			else{
				//Entire body, the end
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|	  |" << endl << "|	  |" << endl << "|	 / \\ " << endl << "| ______________________" << endl;
				cout << "MUCH DEATH, MUCH LOSS" << endl;
			}		
		}
		else if (mode == 1){
			/*Medium mode - 7*/

			/*
			___________
			|         |
			|        \O/
			|		  |
			|		  |
			|		 / \
			|______________________
			*/
			if (attempts == 0){
				return;
			}
			 else if (attempts == 1){
				//Just the hang stand
				cout << "___________" << endl << "|         |" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;

			}
			 else if (attempts == 2){
				 //Head
				 cout << "___________" << endl << "|         |" << endl << "|         O" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			 }
			 else if (attempts == 3){
				 //Left arm, head
				 cout << "___________" << endl << "|         |" << endl << "|        \\O" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			 }
			 else if (attempts == 4){
				 //Left arm, head, right arm
				 cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			 }
			 else if (attempts == 5){
				//Left arm, head, right arm, full body
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|         |" << endl << "|" << endl << "|______________________" << endl;
			}
			 else if (attempts == 6){
				 //Left arm, head, right arm, full body, left leg
				 cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|         |" << endl << "|	 / " << endl << "|______________________" << endl;
			 }
			 else{
				 //Entire body, the end
				 cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|	  |" << endl << "|	  |" << endl << "|	 / \\ " << endl << "| ______________________" << endl;
				 cout << "MUCH DEATH, MUCH LOSS" << endl;
			 }
		}
		else if (mode == 2){
			/*Hard mode - 4 */
			if (attempts == 0){
				//Just the hang stand
				cout << "___________" << endl << "|         |" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 1){
				//Head
				cout << "___________" << endl << "|         |" << endl << "|         O" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 2){
				//Left arm, head, right arm
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else if (attempts == 3){
				//Left arm, head, right arm, full body
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|         |" << endl << "|         |" << endl << "|" << endl << "|______________________" << endl;
			}
			else{
				//Entire body, the end
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|	  |" << endl << "|	  |" << endl << "|	 / \\ " << endl << "| ______________________" << endl;
				cout << "MUCH DEATH, MUCH LOSS" << endl;
			}
		}
		else if (mode == 3){
			/*One mistake = death */
			if (attempts == 0){
				//Just the hang stand
				cout << "___________" << endl << "|         |" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|______________________" << endl;
			}
			else{
				//Entire body, the end
				cout << "___________" << endl << "|         |" << endl << "|        \\O/" << endl << "|	  |" << endl << "|	  |" << endl << "|	 / \\ " << endl << "| ______________________" << endl;
				cout << "MUCH DEATH, MUCH LOSS" << endl;
			}
		}
}

Drawer::~Drawer()
{
}
