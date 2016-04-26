#include<iostream>
#include<string>
#include<fstream>

std::ofstream Thefile("players.txt");

void puttingToText(
  std::string things[3],
  double thingsPoints[3]
  ){
    for(int i=0; i<=2; i++){
      Thefile << things[i] << " : " << thingsPoints[i] << std::endl;
    }
    
  }

void printingItems(
	std::string arrayHelpfull[3],
	double arrayHelpfullPoints[3],
	std::string arrayNone[3],
	double arrayNonePoints[3],
	 std::string arrayHarmfull[3],
	 double arrayHarmfullPoints[3],
	std::string option) {
	  
	  
	std::cout << option << std::endl;
	
	if(option.compare("Plain") == 0){
	  std::cout << arrayNone[0]
	              << " : "
	               << arrayNonePoints[0]
	               <<std::endl
	               << arrayNone[1]
	              << " : "
	               << arrayNonePoints[1]
	               <<std::endl
	               << arrayNone[2]
	              << " : "
	               << arrayNonePoints[2]
	               <<std::endl;
	               
	     puttingToText(arrayNone,arrayNonePoints);
	               
	}
	else if(option.compare("Helpfull") == 0){
	  
	  std::cout << arrayHelpfull[0]
	              << " : "
	               << arrayHelpfullPoints[0]
	               <<std::endl
	               << arrayHelpfull[1]
	              << " : "
	               << arrayHelpfullPoints[1]
	               <<std::endl
	               << arrayHelpfull[2]
	              << " : "
	               << arrayHelpfullPoints[2]
	               <<std::endl;
	  
	  puttingToText(arrayHelpfull,arrayHelpfullPoints);
	}
	else{
	  
	  	  std::cout << arrayHarmfull[0]
	              << " : "
	               << arrayHarmfullPoints[0]
	               <<std::endl
	               << arrayHarmfull[1]
	              << " : "
	               << arrayHarmfullPoints[1]
	               <<std::endl
	               << arrayHarmfull[2]
	              << " : "
	               << arrayHarmfullPoints[2]
	               <<std::endl;
	    puttingToText(arrayHarmfull,arrayHarmfullPoints);
	}
	
}


int main(){
  std::string arrayHelpfull[3] = {"fruits", "soda" , "candy"};
  double arrayHelpfullPoints[3] = {20.4,50.2,30.0};
  
    std::string arrayNone[3] = {"chair", "shoe" , "pencil"};
  double arrayNonePoints[3] = {0,0,0};
  
    std::string arrayHarmfull[3] = {"meth", "dirtyneedle","ninga"};
  double arrayHarmfullPoints[3] = {-20,-50,-30};
  
  int userChoice = 0;
	while (userChoice != 4) {
	  
	  std::cout << "1 - Just Plain Items"
			<< std::endl
			<< "2 - Helpfull Items"
			<< std::endl
			<< "3 - Harmfull Items"
			<< std::endl
			<< "4 - Quit"
			<< std::endl;

		std::cin >> userChoice;

		switch (userChoice) {
		case 1:
			printingItems(
        	arrayHelpfull, arrayHelpfullPoints, arrayNone,
              arrayNonePoints, arrayHarmfull, arrayHarmfullPoints, "Plain"
	     );
			break;
		case 2:
		printingItems(
      	arrayHelpfull, arrayHelpfullPoints, arrayNone,
              arrayNonePoints, arrayHarmfull, arrayHarmfullPoints, "Helpfull"
    	);
		
			break;
		case 3:
		
		printingItems(
      	arrayHelpfull, arrayHelpfullPoints, arrayNone,
              arrayNonePoints, arrayHarmfull, arrayHarmfullPoints, "Harmfull"
    	);
		
			break;
		}
		
	  
	}
}





