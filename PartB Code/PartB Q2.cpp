#include <string>
#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
	MyClass() {
		cout << "Object created";
	}
	~MyClass() {
		cout << "Object destroyed" << endl;
	}
};

int main() {
	cout << "=========================test 2=============================" << endl;
	cout << "Before the block scope" << endl;
	{
		shared_ptr<MyClass> sharedPtr1 = make_shared<MyClass>();
		cout << "SharedPtr1: " << sharedPtr1 << endl;
	}
	cout << "After the function scope" << endl;
	cout << "Checking if MyClass object gets destroyed outside of function" << endl
		//<< "sharedptr1: " << sharedptr1 << endl //causes error
		<< "============================================================" << endl;
	return 0;
}