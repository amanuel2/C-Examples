#include<iostream>
#include<string>
#include<thread>

using std::cout;
using std::endl;
using std::string;

void threadFunc(){
    cout << "Thread Executing" << endl;
}
int main(){
 std::thread t1(&threadFunc);   
 cout << "Hello World" << endl;
 t1.join();
 return 0;
}