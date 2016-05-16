#include<vector>
#include "../Header Files/MasterMind.h"

MasterMind::MasterMind()
{
}

void MasterMind::init()
{
    this -> startGame();
}

int intLength(int i) 
{
    int l=0;
    for(;i;i/=10) l++;
    return l==0 ? 1 : l;
}

template<class T, class VEC>
void resetVariables(T &st1, T &st2, VEC &vec)
{
    st1 = 0; 
    st2 = 0;
    vec.clear();
}

void MasterMind::startGameInst()
{
        cout<<" \n~~~~~MASTER MIND~~~~~ ";    
        cout << "\n\n\t WELCOME TO MASTERMIND \n";
        cout << "The Goal in master mind is to find out the random binary digits i will be placing. \n" ;
        cout << "You have to type in both the numbers, and the correct positions. \n";
        cout << "\n I will tell you how many of the charaters you typed are in correct position, and how much are even correct \n";
        cout << "\n Remember this is Binary... so only 0's and 1's... Good Luck, May the odds be ever in your favor xD! \n";
}

int myRand(int low, int high) 
{
   srand(time(NULL));
   return rand() % (high - low + 1) + low;
}

void MasterMind::startGame()
{
    this -> startGameInst();
    this -> initStartGame();
    this -> gameLoopGame();
    this -> gameLoopFini();
}

void MasterMind::gameLoopFini()
{
    cout << "~~~~~~~~~CONGRATULATIONS! YOU HAVE BEATEN THE MASTERMIND!~~~~~~~~~~~" << endl;
    exit(1);
}
void MasterMind::gameLoopGame()
{
   while(positonCorrect != 4 && actuallyCorrect != 4)
      {
          cout << "\n PLEASE ENTER A 4 DIGIT BINARY! OR PROGRAM WILL EXIT \n\n";
          cin >> binaryCin;
          
          if(intLength(binaryCin) != 4)
                exit(1);
          
          //Converts User Binary to Vector
          evaluateNum(binaryCin);  
          
          //Position
          evaluatePosition();
          //Actuality..
          evaluateCorrection();
          cout << "YOU HAVE " << positonCorrect << " POSITIONS CORRECT \n";
          cout << "YOU HAVE " << actuallyCorrect << " ACTUALLY CORRECT \n";
          if(positonCorrect >= 4 && actuallyCorrect >= 4)
          {
            break;   
          }
          resetVariables(positonCorrect,actuallyCorrect,numbers);
     }
}
void MasterMind::initStartGame()
{
  cout << " \n *****************************************" << endl;
  srand (time(NULL));
  randNum = myRand(8,15);
  convertToBinary(randNum);
  cout  <<endl;    
}

void MasterMind::convertToBinary(int n) 
{
    if (n / 2 != 0)
    {
        convertToBinary(n / 2);
    }
    binaries.push_back(n%2);
}

void MasterMind::evaluatePosition()
{
    if(true)
    {
       int i=0;
       for(std::vector<int>::iterator itAI=binaries.begin() ; itAI != binaries.end(); itAI++, i++)
       {
            char numberAt = numbers.at(i);
            int intNumberAt = numberAt - '0'; 
            if(*itAI == intNumberAt)
            {
                positonCorrect+=1;
            }
        } 
    }
    
}

void MasterMind::evaluateCorrection()
{
  int AI[4] = {0};
  int count = 0;
   std::copy(binaries.begin(), binaries.end(), AI);
   for(std::vector<char>::iterator itAI= numbers.begin() ; itAI != numbers.end(); itAI++)
    {
        for(int i=0; i<=3;i++)
        {
            char numberAt = *itAI;
            int intNumberAt = numberAt - '0'; 
            if(intNumberAt == AI[i])
            {
                actuallyCorrect++;
                break;
            }
        }
    }
}
void MasterMind::evaluateNum(int &bin)
{
    std::string str = std::to_string(bin);
    int count = 0;
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) 
    {
             numbers.push_back(*it);
             count++;
    }
}

MasterMind::~MasterMind()
{
}
    //User : numbers
    //AI : binaries