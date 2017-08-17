#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
void ShowMenu()
{
	cout << "**********************************************" << endl;
	cout << "********欢迎使用自动售卖机，请输入您的选择*******" << endl;
	cout << "* 1.下订单                                     " << endl;
	cout << "* 2.退出自动售卖                               " << endl;
	cout << "**********************************************" << endl;
}

int GetInteger()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)
		cin.getline(buf, 100);
	//int atoi(char *)将字符串转换成int
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
	cout << "********欢迎使用自动售卖机，请输入您的选择*******" << endl;
	cout << "* 1.买香蕉                                     " << endl;
	cout << "* 2.买苹果                                     " << endl;
	cout << "* 3.显示总价格                                 " << endl;
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
		cout << "已经购买水果的总价：" << fixed << setprecision(2) << setw(8) << sum << "元" << endl;
		cout << "您的选择是：";
		int input = GetInteger();
		double weight = 1;
		switch (input)
		{
		case 1:
			//todo banana
			//todo apple
			cout << "请输入称重（公斤）：";
			weight = GetDouble();
			sum += banana_price*weight;
			banana_weight += weight;
			break;
		case 2:
			//todo apple
			cout << "请输入称重（公斤）：";
			weight = GetDouble();
			sum += apple_price*weight;
			apple_weight += weight;
			break;
		case 3:
			//todo:显示总价格

			if (sum > 0)
			{
				cout << "您一共购买了";
				if (fabs(apple_weight) > 1E-6)
					cout << apple_weight << "公斤苹果， ";
				if (fabs(banana_weight) > 1E-6)
					cout << banana_weight << "公斤香蕉， ";
				cout << "总价是：" << sum << "元" << endl;
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
		cout << "您的选择是：";
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


