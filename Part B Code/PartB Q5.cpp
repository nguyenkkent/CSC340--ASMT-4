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

	int main() {
		shared_ptr<MyClass> sptr = make_shared<MyClass>(30);
		//cout << sptr.use_count() << endl;
		return 0;
			
}

};