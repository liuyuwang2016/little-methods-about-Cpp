#include <iostream>
#include <string>
using namespace std;

class Src {
public:
	Src() { cout << "Src::Src()" << endl; }
	/*operator Dst() const {
	cout << "Src::operator Dst() called" << endl;
	return Dst();
	}*/
};
//class Src;//ǰ����������
class Dst {
public:
	Dst() { cout << "Dst::Dst()" << endl; }
	Dst(const Src& s) {
		cout << "Dst::Dst(const Src&)" << endl;
	}
};

void Func(Dst d) {}

int main()
{
	Src s;
	Dst d1(s);
	/*��S��Ϊ��������d1�Ĳ������*/
	Dst d2 = s;
	Func(s);

	return 0;
}