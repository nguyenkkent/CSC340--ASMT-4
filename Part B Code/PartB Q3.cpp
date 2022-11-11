#include <string>
#include <iostream>
#include <memory>
using namespace std;

class MyClass {
private:
	int value;

public:
	MyClass(int value){
		this->value = value;
		cout << "Object created" <<endl;
	}
	int getData() {
		return value;
	}
	
};


int main() {
	
	unique_ptr<MyClass> uniquePtr = make_unique<MyClass>(5);
	cout<< "uniquePtr address:" << &uniquePtr << endl
		<< "UniquePtr .get(): " << uniquePtr.get() << endl
		<< "UniquePtr.reset" << endl;
	MyClass* rawPtr = { uniquePtr.release() };
	cout << "uniquePtr address:" << &uniquePtr << endl
		<< "UniquePtr .get(): " << uniquePtr.get() << endl
		<< "rawPtr addres: " << &rawPtr << endl
		<< "rawPtr owns obj @: " << rawPtr;

}