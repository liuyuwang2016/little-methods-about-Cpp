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
//class Src;//前置类型申明
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
	/*以S作为参数构造d1的参数语句*/
	Dst d2 = s;
	Func(s);

	return 0;
}