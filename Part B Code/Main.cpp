//ASMT 4 Part B
using namespace std;
#include <string>
#include <iostream>
#include <memory>

class MyClass {
public:
	MyClass() {
		cout << "Object created";
	}
	~MyClass() {
		cout << "Object destroyed";
	}
};


void partBNumberOne() {
	string* ptr1 = new string("Fun test");
	string* ptr2 = ptr1;

	cout << "Checking if both pointers point to the same memory address:" << endl
		<< "=========================test 1============================="
		<< "mem address that ptr1 holds: " << ptr1 << endl
		<< "mem address that prt2 holds: " << ptr2 << endl
		<< "============================================================" << endl;

	delete ptr1;
	ptr1 = nullptr;
	//delete ptr2; //crashes with error
	//ptr2 = nullptr; //crashes with error


}

void partBNumberTwo() {
	cout << "Checking to see " << endl
	
}



int main() {
	partBNumberOne();

	partBNumberTwo();



}