//ASMT 4 Part B
using namespace std;
#include <string>
#include <iostream>

void partBNumberOne() {
	string str = "Fun test";
	string* ptr1 = &str;
	string* ptr2 = &str;

	cout << "Checking if both pointers point to the same memory address:" << endl
		<< "mem address that ptr1 holds: " << ptr1 << endl
		<< "mem address that prt2 holds: " << ptr2 << endl;

	delete ptr1;
	ptr1 = nullptr;
	//delete ptr2; //crashes with error
	//ptr2 = nullptr; //


}


int main() {
	partBNumberOne();

}