#include "../Header Files/BinaryFight.h"

BinaryFight::BinaryFight()
{
}

void BinaryFight::init()
{
    this -> printInst();
    this -> startGame();
    exit(1);
}

void printVecInt(std::vector<int>AICORRECT)
{
    for(std::vector<int>::iterator it = AICORRECT.begin(); it!=AICORRECT.end(); it++)
        cout << *it;
}

void BinaryFight::startGame()
{
    for(int i=1; i<=3;i++)
        this->binaryRounds(i);
    this->resultsPrt();
}

void BinaryFight::printInst()
{
        cout<<" \n~~~~~BINARY FIGHT~~~~~ ";    
        cout << "\n\n\t WELCOME TO BINARY FIGHT \n";
        cout << "The Goal of Binary Fight, is to anwser the requested binary as fast as possible \n" ;
        cout << "I will time you, and give you your timing when you finish 3. \n";
        cout << "\n I Will give you for the first one, second one, third one, and ofcourse your Average time \n";
        cout << "\n I Will give you a binary number after 3 seconds! Get Ready!! \n";
        cout << "\n Remember this is Binary... so only 0's and 1's... Good Luck, May the odds be ever in your favor xD! \n";
}

void BinaryFight::binaryRounds(int count)
{
    if(count == 1)
    {
        std::cout << "******FIRST BINARY******** \n";
        srand (time(NULL));
        rand1 = myRand(8,15);
        convertToBinary(rand1,correctF);
        std::cout << "DECIMAL IS " << rand1 << endl;
        cout << "\n PLEASE ENTER BINARY OF ABOVE!\n";
    
        timer.Start();
        std::cin >> userGs1; 
        timer.Stop();
        timesPassedVec.push_back(timer.getTimeSeconds());
        checkCorrectness(userGs1,correctF,correctFB); 
    }
    else if(count == 2)
    {
        std::cout << "\n\n******SECOND BINARY******** \n";
        srand (time(NULL));
        rand2 = myRand(8,15);
        convertToBinary(rand2,correctS);
        std::cout << "DECIMAL IS " << rand2 << endl;
        cout << "\n PLEASE ENTER BINARY OF ABOVE!\n";
        
        timer.Reset();
        std::cin >> userGs2; 
        timer.Stop();
        timesPassedVec.push_back(timer.getTimeSeconds());
        checkCorrectness(userGs2,correctS,correctSB);
    }
    else
    {
        std::cout << "\n\n******THIRD BINARY******** \n";
        srand (time(NULL));
        rand3 = myRand(8,15);
        convertToBinary(rand3,correctT);
        std::cout << "DECIMAL IS " << rand3 << endl;
        cout << "\n PLEASE ENTER BINARY OF ABOVE!\n";
        timer.Reset();
        std::cin >> userGs3; 
        timer.Stop();
        timesPassedVec.push_back(timer.getTimeSeconds());
        checkCorrectness(userGs3,correctT,correctTB);
    }
}

void printVecIntRst(std::vector<int> intVec){
    for(std::vector<int>::iterator itNest=intVec.begin(); itNest!=intVec.end(); itNest++)
            cout << *itNest;
}
void BinaryFight::resultsPrt()
{
    std::cout << "\n\n**************************FINISHED**************************\n";
    int countFini = 1;
    cout << "1 For Correct, 0 For Incorrect \n\n";
    for(std::vector<int>::iterator it = timesPassedVec.begin(); it!=timesPassedVec.end(); it++, countFini++)
    {
        if(countFini == 1)
        {
            cout << "1) "<< " TIME : " << *it << " Correct : " << correctFB << endl;
            cout << "    You Typed : " << userGs1 << std::endl;
            cout << "    Correct Binary : ";
            printVecIntRst(correctF);
            cout << endl;  
            averageNum += *it;
        }
        else if(countFini == 2)
        {
            cout << "2) "<< " TIME : " << *it << " Correct : " << correctSB << endl;
            averageNum += *it;
            cout << "    You Typed : " << userGs2 << std::endl;
             cout << "    Correct Binary : ";
            printVecIntRst(correctS);
            cout << endl;  
            averageNum += *it;
        }
        else
        {
            cout << "3) "<< " TIME : " << *it << " Correct : " << correctTB << endl;
            averageNum += *it;
            cout << "    You Typed : " << userGs3 << std::endl;
             cout << "    Correct Binary : ";
            printVecIntRst(correctT);
            cout << endl;  
            averageNum += *it;
        }
        countFini++;
    }
    cout << "AVERAGE TIME (in seconds) :  " << (averageNum/3) << endl; 
}
void BinaryFight::checkCorrectness(int userGuess, std::vector<int>AICORRECT, bool &correctB)
{
    std::string AICORRECTSTR = "";
    std::string userGuessString = std::to_string(userGuess);
    for(std::vector<int>::iterator it = AICORRECT.begin(); it!=AICORRECT.end(); it++)
    {
        AICORRECTSTR = AICORRECTSTR + std::to_string(*it);   
    }
    if(AICORRECTSTR.compare(userGuessString) != 0 )
    {
        correctB = false;
    }
    else
    {
        correctB = true;
    }
}

void BinaryFight::convertToBinary(int n, std::vector<int> &correct) 
{
    if (n / 2 != 0)
    {
        convertToBinary(n / 2 , correct);
    }
    correct.push_back(n%2);
}



BinaryFight::~BinaryFight()
{
}


