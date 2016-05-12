#include<iostream>
#include<string>
#include<thread>

using std::cout;
using std::endl;
using std::string;
using std::thread;


int main(){
    thread t1([]()
    {
        cout << " \n Hello From Thread 1" << endl;
    });
    
    t1.detach();
    cout << " \n HEllo from Main Thread" << endl;
    
}