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

int main() {
	unique_ptr<MyClass> uniquePtr4{ make_unique<MyClass>(25) };
	//unique_ptr<MyClass> uniquePtr5 = uniquePtr4;//cannot make a second pointer sharing the same ownership of object
	shared_ptr<MyClass> sharedPtr6 = move(uniquePtr4);
	cout << "address of uniquePtr4: " << &uniquePtr4 << endl
		 << "value that uniquePtr4 holds: " << uniquePtr4.get()<< endl
		 << "address of sharedPtr6: " << &sharedPtr6 << endl
		 << "value that sharedPtr6 holds: " << sharedPtr6->getData() << endl;

	return 0;
}