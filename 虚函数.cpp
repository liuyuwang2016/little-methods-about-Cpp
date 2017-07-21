#include <iostream>
#include <string>
using namespace std;

class B {
public:
	virtual void show() { cout << "B.show()\n"; }
	~B() { cout << "~B()\n" << endl; }
};

class D : public B {
public:
	void show() { cout << "D.show()\n"; }
	~D() { cout << "~D()\n"; }
};

void test(B* ptr) {
	ptr->show();
}

int main() {
	B* ptr = new D;
	test(ptr);
	delete ptr;
	return 0;
}