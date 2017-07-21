#include <iostream>
#include <string>
using namespace std;

class T {};

class B {
public:
	void f() { cout << "B::f()\n"; }
	void f(int i) { cout << "B::f(" << i << ")\n"; }
	void f(double d) { cout << "B::f(" << d << ")\n"; }
	void f(T) { cout << "B::f(T)\n"; }
};

class D1 :public B {
public:
	/*函数重写之后会自动屏蔽基类原来的其他重载函数*/
	void f(int i) { cout << "D1::f(" << i << ")\n"; }
	/*using classname::functionName可以消去屏蔽*/
	using B::f;
};

int main() {
	D1 d;
	d.f(10);
	d.f(4.9);
	d.f();
	d.f(T());
	return 0;
}
