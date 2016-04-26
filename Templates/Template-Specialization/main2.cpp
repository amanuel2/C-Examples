#include<iostream>
#include<string>

template<class F, class S>
class addingStuff {
public:
	addingStuff(F fCons, S sCons) : f(fCons), s(sCons){}

	F addingStuffFunc();

private:
	F f; S s;
};

template<class F, class S>
F addingStuff<F, S>::addingStuffFunc() {
	return(f + s);
}

template<>
class addingStuff<std::string , std::string>{
public:
	addingStuff(std::string sConst, std::string s2Const):s(sConst), s2(s2Const){}	
	std::string addingStuffFunc();
private:
	std::string s, s2;
};


std::string addingStuff<std::string, std::string>::addingStuffFunc() {
	return "Sorry.. Adding strings is Illegal!!";
}

int main() {
	addingStuff<std::string, std::string> exampleStuff("Hello " , "World");
	std::cout << exampleStuff.addingStuffFunc() << std::endl;
}
