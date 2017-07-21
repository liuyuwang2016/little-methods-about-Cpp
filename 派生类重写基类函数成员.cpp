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
	/*������д֮����Զ����λ���ԭ�����������غ���*/
	void f(int i) { cout << "D1::f(" << i << ")\n"; }
	/*using classname::functionName������ȥ����*/
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
