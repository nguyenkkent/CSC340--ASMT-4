using namespace std;
#include <string>
#include <iostream>
#include <memory>

int main() {

	string* ptr1 = new string("Fun test");
	string* ptr2 = ptr1;

	cout << "=========================test 1=============================" << endl
		<< "Checking if both pointers point to the same memory address:" << endl
		<< "mem address that ptr1 holds: " << ptr1 << endl
		<< "mem address that prt2 holds: " << ptr2 << endl
		<< "============================================================" << endl;

	delete ptr1;
	ptr1 = nullptr;
	//delete ptr2; //crashes with error
	//ptr2 = nullptr; //crashes with error
}