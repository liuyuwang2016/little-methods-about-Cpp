#include <iostream>
#include <string>
using namespace std;
//��̬��Ա�����Ĳ�������û�� this ָ�룬���Բ��ܵ��÷Ǿ�̬��Ա����

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
	//obj2�ǳ������󣬶�who���ǣ�����who�п��ܻ�ı�obj2
	cout << "id_2 = " << obj2.Who() << endl;

	return 0;
}