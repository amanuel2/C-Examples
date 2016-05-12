#include<iostream>
#include<string>
#include<thread>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class Fctor{
    public:
        void operator()(std::string &msg){
            for(int i=0;i<=10;i++)
                cout << i << msg <<endl;
        }
};
int main(){
    Fctor fct;
    //std::thread workers(fct, std::ref(r)); or std::thread workers(Fctor(), std::ref(r));
    std::string r = ": THIS IS THREAD 1";
    /*std::move is more efficent than std::ref
     **Since it actually moves the "variable"
     **To the actual class than just giving
     **the class the memory adress
    */
    std::thread workers(fct, std::move(r));
    cout << workers.get_id() << endl;
    
    try{
        for(int i=0; i<=100 ; i++)
            cout << i << ": From Main" <<endl;
    }catch(...){
        cout << "THREAD 1 CONTROLLING" << endl;
        workers.join();
    }
    
    workers.join();
}