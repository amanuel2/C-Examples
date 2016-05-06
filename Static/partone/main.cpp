#include <iostream>
#include <string>

class STATICEX{
private:
    static int exVarW;
public:

    STATICEX(int value){
    //You May Only Initalize
    //A Static Member inside a
    //constructur if you are talking
    //about in-class
    static int someStat = value;
    }
    /*Static Functions can only
    Access Static Members. And
    Non-Static Functions can not access
    Static members, or functions.*/
    static void setVar(int val){
     exVarW = val;
    }
    static int getVar(){
     return exVarW;
    }
};

/*
* Static Members of Class
* Cant be initalized in class
* it self. But can be accessed
* without the need of object instance
* But if it is a private member, it has
* to be get by a getter, or an object/method.
*/
int STATICEX::exVarW = 5;

int main()
{
    STATICEX exStat;
    exStat.setVar(5);
    std::cout << exStat.getVar() << std::endl;
}

