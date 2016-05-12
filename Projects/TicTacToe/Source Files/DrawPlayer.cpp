#include "../Header Files/DrawPlayer.h"



DrawPlayer::DrawPlayer()
{
}


void DrawPlayer::drawP(string character, int position)
{
   
   /********************************
*   1   *     2       *   3   *
*       *             *       *
*******************************
*       *             *       *
*  4    *     5       *  6    *
*       *             *       *
*******************************
*  7    *    8        *  9    *
*       *             *       *
********************************/
unsigned short COUNTX = 0;
switch(position){
    case 9:
		cout  << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
			<< endl;
		for(int i =0; i<=31;i++){
			if(COUNTX == 26){
				cout << character <<"\x1b[A" << endl;
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
			for(int place = 0; place <= 6; place++)
				cout << endl;
	
	case 8:
	    

    		cout  << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
    			<< endl;
    		for(int i =0; i<=20;i++){
    			if(COUNTX == 15){
    				cout << character <<"\x1b[A" << endl;
    	
    				COUNTX++;
    			}
    			else{
    				cout << " ";
    				COUNTX++;
    			}
    		}
    		
    		for(int place = 0; place <= 6; place++)
    				cout << endl;
    				
    case 7:
        
        		cout << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
        			<< endl;
        		for(int i =0; i<=7;i++){
        			if(COUNTX == 4){
        				cout << character <<"\x1b[A" << endl;
        				COUNTX++;
        			}
        			else{
        				cout << " ";
        				COUNTX++;
        			}
        		}
        			for(int place = 0; place <= 4; place++)
        				cout << endl;
        				
    case 6:
		cout  << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" << endl;
		for(int i =0; i<=31;i++){
			if(COUNTX == 26){
				cout << character <<"\x1b[A" << endl;
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
			for(int place = 0; place <= 6; place++)
				cout << endl;
				
	case 5:
		cout << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
			<< endl;
		for(int i =0; i<=20;i++){
			if(COUNTX == 15){
				cout << character <<"\x1b[A" << endl;
	
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
		
		for(int place = 0; place <= 6; place++)
				cout << endl;
	
	case 4:
	    
        		cout  << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
        			<< endl;
        		for(int i =0; i<=7;i++){
        			if(COUNTX == 4){
        				cout << character <<"\x1b[A" << endl;
        				COUNTX++;
        			}
        			else{
        				cout << " ";
        				COUNTX++;
        			}
        		}
        			for(int place = 0; place <= 10; place++)
        				cout << endl;
        				
    case 3:
		cout << "\x1b[A" <<"\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
			<< endl;
		for(int i =0; i<=31;i++){
			if(COUNTX == 26){
				cout << character <<"\x1b[A" << endl;
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
			for(int place = 0; place <= 10; place++)
				cout << endl;    
				
	case 2: // <---- CAS?
		cout << "\x1b[A" <<"\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
			<< endl;
		for(int i =0; i<=20;i++){
			if(COUNTX == 15){
				cout << character <<"\x1b[A" << endl;
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
		
		for(int place = 0; place <= 10; place++)
				cout << endl;
	    
	case 1:
		cout << "\x1b[A" <<"\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A" << "\x1b[A"  << "\x1b[A" <<"\x1b[A" 
			<< endl;
		for(int i =0; i<=7;i++){
			if(COUNTX == 4){
				cout << character <<"\x1b[A" << endl;
				COUNTX++;
			}
			else{
				cout << " ";
				COUNTX++;
			}
		}
			for(int place = 0; place <= 10; place++)
				cout << endl;
	
	default:
		try{
			if(true)
				throw "NOT POSSIBLE NUMBER";
		}catch(char const *error){
			exit(1);
		}
	    
}

				
	
}

DrawPlayer::~DrawPlayer()
{
}
