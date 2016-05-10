#include<iostream>

using std::cout;
using std::endl;

int main(){
    int stff = 5;
    //00000101
    
    stff = stff << 1;
    //00000101 << 1
    //00001010
    //= 10
    
    cout << stff <<endl;
}
