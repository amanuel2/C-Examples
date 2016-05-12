#include<iostream>
#include<string>
#include<thread>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::thread;


void func(int tid) 
  {
      cout << "Launched by thread " << tid << endl;
  }
 
int main() 
{
    std::vector<thread> th;
 
   int nr_threads = 10;
   
   //Launch a group of threads
   for (int i = 0; i < nr_threads; ++i) 
       th.push_back(std::thread(func,i));
 

    //Join the threads with the main thread
 for(auto &t : th)
      t.detach();
      
      
      
  /*So Basically in a simulation of t1.. main thread  
    waits for all the other threads..
    Launched by thread 0Launched by thread 
    1
    Launched by thread 4
    Launched by thread Launched by thread 2
    Launched by thread Launched by thread 7
    5
    Launched by thread 9
    Launched by thread 3
    6
    Launched by thread 8
    LAUNCHED BY THE BIG BOSS. MAIN THREAD
  */
  
  /*
  *Now in the simulation of t1 detaching t1.detach();
  *it dosent have to wait for the main thread to finish
  
  */
      
  std::cout << "LAUNCHED BY THE BIG BOSS. MAIN THREAD" << std::endl;      
 
     return 0;
 }