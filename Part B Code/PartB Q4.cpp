#include <string>
#include <iostream>
#include <memory>
using namespace std;

class MyClass {
private:
	int value;

public:
	MyClass(int value) {
		this->value = value;
		cout << "Object created" << endl;
	}
	int getData() {
		return value;
	}

};