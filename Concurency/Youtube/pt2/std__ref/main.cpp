#include<iostream>
#include<string>
#include<vector>
#include<thread>

using std::cout;
using std::endl;
using std::thread;
using std::string;
using std::vector;


/*
*TYPE : RACE
*DESC: Racing Condition while, all the 10 threads created,
*race to execute...
*Think of the gophers cars..
*/
void worstHashEver(int &nonHashed){
    nonHashed = (nonHashed % (nonHashed % 3));
}

void func(int ID, int &HASHED)
{
    cout << "THREAD " << ID << " HASH : " << HASHED << endl;
}

void pushWorkersVec(vector<thread> &workers)
{
     for(int i=0; i<=10; i++){
        int j = i-3;
        //This will result in an error:
        //workers.push_back(std::thread(&func, i, (j)));
        workers.push_back(std::thread(&func, i, std::ref(j)));
    }
}
void itterateThroughThread(vector<thread> &workers)
{
    //"Javascript For Each"...
     for(auto &t: workers)
        t.join();
}

int main()
{
    vector<thread> workers;
    pushWorkersVec(workers);
    itterateThroughThread(workers);
    cout << "MAIN THREAD" << endl;    
}
