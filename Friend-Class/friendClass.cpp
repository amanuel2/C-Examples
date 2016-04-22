#include <iostream>
#include <string>

class Sally {
	friend class Amanuel;
private:
	int sallyPrivateID;
};

class Amanuel {
public:
	int getSallyId(Sally sally) {
		return sally.sallyPrivateID;
	}
	int getID() {
		return amanuelPrivateID;
	}
private:
	int amanuelPrivateID;
};
int main() {
	Sally sally;
	Amanuel amanuel;

	//Amanuel Can Acess Sally because its a friend class..
	/**
	** Diffrence Between Friend Class and Getter/Setter
	*/
	std::cout << amanuel.getSallyId(sally) << std::endl;
}
