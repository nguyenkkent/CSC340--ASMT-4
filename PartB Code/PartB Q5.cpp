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
	//MyClass* rawPtr1 = new MyClass(5);
	//auto* rawPtr2 = rawPtr1;
	//cout<< "Address of rawPtr1: " << &rawPtr1 << endl
	//	<< "Pointee of rawPtr1: " << rawPtr1->getData() << endl
	//	<< "Address of rawPtr2: " << &rawPtr2 << endl
	//	<< "Pointee of rawPtr2: " << rawPtr2->getData() << endl;

	//delete rawPtr1;
	//rawPtr1 = nullptr;
	//cout << "after rawPtr1 is deleted we still have rawPtr2 dangling that points to: "<< rawPtr2->getData();

	shared_ptr<MyClass> sptr {new MyClass(5)};
	weak_ptr<MyClass> wptr{ sptr };

	cout << "Number of Owners for wptr: " << wptr.use_count() << endl;
	sptr.reset();
	cout << "Reseting shared_ptr" << endl;
	cout << "Number of Owners for wptr: " << wptr.use_count() << endl;
	

	return 0;

}