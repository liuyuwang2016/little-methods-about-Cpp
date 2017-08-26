// �Զ����������ļ�����ˮ���ͼ۸� 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

struct Fruit_t
{
	char name[20];
	double price;
};

void ShowMenu()
{
	cout << "****************************************" << endl;
	cout << "* ��ӭʹ���Զ�������������������ѡ�� *" << endl;
	cout << "* 1. �¶���                            *" << endl;
	cout << "* 2. �˳��Զ�����                      *" << endl;
	cout << "****************************************" << endl;
}

int GetInteger()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)	// ����ֱ�ӻس�
		cin.getline(buf, 100);
	return atoi(buf);
}

double GetDouble()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)	// ����ֱ�ӻس�
		cin.getline(buf, 100);
	return atof(buf);
}

// �������ļ���������ˮ�����ƺ͵��� 
bool GetFruits(Fruit_t *&fruits, int &fruit_number);

void DealOrder(Fruit_t *fruits, int fruit_number);

int main()
{
	Fruit_t *fruits = 0;
	int fruit_number;
	if (!GetFruits(fruits, fruit_number))
	{
		cout << "ˮ�������ļ�����" << endl;
		return 0;
	}

	while (1)
	{
		ShowMenu();
		cout << "����ѡ���ǣ�";
		int input = GetInteger();
		switch (input)
		{
		case 1:
			DealOrder(fruits, fruit_number);
			break;
		case 2:
			delete[]fruits;
			return 0;
		}
	}
}

void ShowSubMenu(Fruit_t *fruits, int fruit_number)
{
	cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+ ��ѡ����Ҫ�Ĳ�����                   +" << endl;
	for (int i = 0; i < fruit_number; i++)
	{
		//setw���
		cout << "+" << setw(2) << i + 1 << ". ����";
		//setprecision����������ȣ�С���������λ
		cout << fruits[i].name << "(" << fixed << setw(5) << setprecision(2) << fruits[i].price << "Ԫ/����)";
		//
		int len = strlen(fruits[i].name);
		//���ʹ�ÿո��Ű棬16��ȥˮ�����ֵĳ��ȣ����ǿո�ĸ���
		for (int j = 0; j < 16 - len; j++)
			cout << ' ';
		cout << "+" << endl;
	}
	cout << "+" << setw(2) << fruit_number + 1 << ". ����                              +" << endl;
	cout << "+" << setw(2) << fruit_number + 2 << ". ��������                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
}

void DealOrder(Fruit_t *fruits, int fruit_number)
{
	double *weight = new double[fruit_number];
	for (int i = 0; i < fruit_number; i++)
		weight[i] = 0;
	double sum = 0;
	while (1)
	{
		ShowSubMenu(fruits, fruit_number);
		cout << "�ѹ���ˮ���ܼۣ�" << fixed << setprecision(2) << setw(8) << sum << "Ԫ" << endl;
		cout << "����ѡ���ǣ�";
		int input = GetInteger();//�õ�����һ��ˮ��
		if (input > 0 && input <= fruit_number)
		{
			cout << "���������(�����";
			double w = GetDouble();
			sum += fruits[input - 1].price * w;
			weight[input - 1] += w;
		}
		else if (input == fruit_number + 1)
		{
			if (sum > 1E-6)    // ȷʵ����ˮ�� 
			{
				cout << "��һ��������";
				for (int i = 0; i < fruit_number; i++)
					if (fabs(weight[i]) > 1E-6)
						cout << weight[i] << "����" << fruits[i].name << "��";
				cout << "�ܼ���" << sum << "Ԫ" << endl;
				system("pause");
			}
			break;
		}
		else if (input == fruit_number + 2)
			break;
	}
	delete[]weight;
	system("cls");
}

bool GetFruits(Fruit_t *&fruits, int &fruit_number)
{
	ifstream fin("fruits.txt");
	//û�д򿪵Ļ�Ҫ����һ��
	if (!fin)
		return false;
	fin >> fruit_number;
	//ws��endl��һ����˼������Ŀհ׵Ĳ�������
	fin >> ws;
	fruits = new Fruit_t[fruit_number];
	for (int i = 0; i < fruit_number; i++)
	{
		char buffer[100];
		fin.getline(buffer, 100);
		//strchr��string����Ѱ��һ��character������һ��ָ�룬λ����=���ŵ�λ��
		char *p = strchr(buffer, '=');
		*p = '\0';
		//����strcpy
		strcpy(fruits[i].name, buffer);
		//atof���ַ���ת���ɸ�����
		fruits[i].price = atof(p + 1);
	}
	fin.close();
	return true;
}


