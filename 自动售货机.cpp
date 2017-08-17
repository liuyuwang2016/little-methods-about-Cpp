#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
void ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "********��ӭʹ���Զ�������������������ѡ��*******" << endl;
	cout << "* 1.�¶���                                     " << endl;
	cout << "* 2.�˳��Զ�����                               " << endl;
	cout << "**********************************************" << endl;
}

int GetInteger()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)
		cin.getline(buf, 100);
	//int atoi(char *)���ַ���ת����int
	return atoi(buf);
}

double GetDouble()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)
		cin.getline(buf, 100);
	return atof(buf);
}

void ShowSubMenu()
{
	cout << "**********************************************" << endl;
	cout << "********��ӭʹ���Զ�������������������ѡ��*******" << endl;
	cout << "* 1.���㽶                                     " << endl;
	cout << "* 2.��ƻ��                                     " << endl;
	cout << "* 3.��ʾ�ܼ۸�                                 " << endl;
	cout << "**********************************************" << endl;
}

void DealOrder()
{
	double apple_price = 3.5;
	double apple_weight = 0;
	double banana_price = 4.2;
	double banana_weight = 0;
	double sum = 0;
	while (1)
	{
		ShowSubMenu();
		cout << "�Ѿ�����ˮ�����ܼۣ�" << fixed << setprecision(2) << setw(8) << sum << "Ԫ" << endl;
		cout << "����ѡ���ǣ�";
		int input = GetInteger();
		double weight = 1;
		switch (input)
		{
		case 1:
			//todo banana
			//todo apple
			cout << "��������أ������";
			weight = GetDouble();
			sum += banana_price*weight;
			banana_weight += weight;
			break;
		case 2:
			//todo apple
			cout << "��������أ������";
			weight = GetDouble();
			sum += apple_price*weight;
			apple_weight += weight;
			break;
		case 3:
			//todo:��ʾ�ܼ۸�

			if (sum > 0)
			{
				cout << "��һ��������";
				if (fabs(apple_weight) > 1E-6)
					cout << apple_weight << "����ƻ���� ";
				if (fabs(banana_weight) > 1E-6)
					cout << banana_weight << "�����㽶�� ";
				cout << "�ܼ��ǣ�" << sum << "Ԫ" << endl;
			}
			system("pause");
		case 4:
			system("cls");
			return;
		}
	}
}
int main()
{
	while (1)
	{
		ShowMenu();
		cout << "����ѡ���ǣ�";
		int input = GetInteger();
		cin >> input;
		switch (input)
		{
		case 1:
			DealOrder();
			break;
		case 2:
			return 0;
		}
	}
}


