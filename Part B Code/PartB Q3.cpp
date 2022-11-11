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

void partBNumberThree() {
	unique_ptr<MyClass> uniquePtr = make_unique<MyClass>(5);
	cout << "uniquePtr address:" << &uniquePtr << endl
		<< "UniquePtr .get(): " << uniquePtr.get() << endl
		<< "UniquePtr.reset" << endl;
	MyClass* rawPtr = { uniquePtr.release() };
	cout << "uniquePtr address:" << &uniquePtr << endl
		<< "UniquePtr .get(): " << uniquePtr.get() << endl
		<< "rawPtr addres: " << &rawPtr << endl
		<< "rawPtr owns obj @: " << rawPtr << endl;
}




int main() {
	partBNumberThree();

	cout<< "Another example of if an there is no longer an ownership to an object (pointer is deleted "
		<< "then the object dies with it's pointer" << endl;
	{
		unique_ptr<MyClass> uniquePtr2 = make_unique<MyClass>(10);
		cout << "Within block uniquePtr2 value: " << uniquePtr2->getData() << endl;
	}
	//cout << uniquePtr2.get(); //can no longer access object's data member outside of block

	return 0;
}