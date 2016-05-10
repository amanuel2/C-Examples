#include<iostream>

using std::cout;
using std::endl;

int main(){
    int stff = 25;
    //01000001
    
    stff = stff >> 1;
    //00011001 >> 1
    //00001100
    //=12
    
    cout << stff << endl;
}
