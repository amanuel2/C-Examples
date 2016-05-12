#include<iostream>
#include<string>
#include<thread>

using std::cout;
using std::endl;
using std::string;


void helloWorld()
{
   for(int i=0;i<10;i++)
        cout << " \nHello World from Thread" << endl;
}
int main()
{
    /*
    *In This Case since we called
    *.join(); mainthread will wait for
    *t1 to finish then execute its 
    *functions.. which isnt really
    *concurent in my oppinon.
    */
    std::thread t1(helloWorld);
    t1.join();
    
    for(int i=0; i<=10;i++)
        cout << " \n Hello world from main thread" << endl; 

}