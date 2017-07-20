#include <iostream>
#include <string>
using namespace std;
//静态成员函数的参数里面没有 this 指针，所以不能调用非静态成员函数

class Test {
	const int ID;
public:
	Test(int id) :ID(id) {}
	int MyID() const { return ID; }
	int Who() const { return ID; }
};

int main()
{
	Test obj1(20152197);
	cout << "ID_1 = " << obj1.MyID() << endl;
	cout << "ID_2 = " << obj1.Who() << endl;

	const Test obj2(20169800);
	cout << "id_1 = " << obj2.MyID() << endl;
	//obj2是常量对象，而who不是，所以who有可能会改变obj2
	cout << "id_2 = " << obj2.Who() << endl;

	return 0;
}