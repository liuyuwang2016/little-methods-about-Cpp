// 自动售卖，从文件读入水果和价格 
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
	cout << "* 欢迎使用自动售卖机，请输入您的选择。 *" << endl;
	cout << "* 1. 下订单                            *" << endl;
	cout << "* 2. 退出自动售卖                      *" << endl;
	cout << "****************************************" << endl;
}

int GetInteger()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)	// 输入直接回车
		cin.getline(buf, 100);
	return atoi(buf);
}

double GetDouble()
{
	char buf[100] = { 0 };
	while (strlen(buf) == 0)	// 输入直接回车
		cin.getline(buf, 100);
	return atof(buf);
}

// 从配置文件读入所有水果名称和单价 
bool GetFruits(Fruit_t *&fruits, int &fruit_number);

void DealOrder(Fruit_t *fruits, int fruit_number);

int main()
{
	Fruit_t *fruits = 0;
	int fruit_number;
	if (!GetFruits(fruits, fruit_number))
	{
		cout << "水果配置文件错误！" << endl;
		return 0;
	}

	while (1)
	{
		ShowMenu();
		cout << "您的选择是：";
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
	cout << "+ 请选择您要的操作。                   +" << endl;
	for (int i = 0; i < fruit_number; i++)
	{
		//setw宽度
		cout << "+" << setw(2) << i + 1 << ". 购买";
		//setprecision设置输出精度，小数点后保留两位
		cout << fruits[i].name << "(" << fixed << setw(5) << setprecision(2) << fruits[i].price << "元/公斤)";
		//
		int len = strlen(fruits[i].name);
		//这里。使用空格并排版，16减去水果名字的长度，就是空格的个数
		for (int j = 0; j < 16 - len; j++)
			cout << ' ';
		cout << "+" << endl;
	}
	cout << "+" << setw(2) << fruit_number + 1 << ". 结账                              +" << endl;
	cout << "+" << setw(2) << fruit_number + 2 << ". 放弃购买                          +" << endl;
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
		cout << "已购买水果总价：" << fixed << setprecision(2) << setw(8) << sum << "元" << endl;
		cout << "您的选择是：";
		int input = GetInteger();//得到是哪一种水果
		if (input > 0 && input <= fruit_number)
		{
			cout << "请输入称重(公斤）：";
			double w = GetDouble();
			sum += fruits[input - 1].price * w;
			weight[input - 1] += w;
		}
		else if (input == fruit_number + 1)
		{
			if (sum > 1E-6)    // 确实买了水果 
			{
				cout << "您一共购买了";
				for (int i = 0; i < fruit_number; i++)
					if (fabs(weight[i]) > 1E-6)
						cout << weight[i] << "公斤" << fruits[i].name << "，";
				cout << "总价是" << sum << "元" << endl;
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
	//没有打开的话要报错一下
	if (!fin)
		return false;
	fin >> fruit_number;
	//ws和endl是一个意思，后面的空白的部分跳过
	fin >> ws;
	fruits = new Fruit_t[fruit_number];
	for (int i = 0; i < fruit_number; i++)
	{
		char buffer[100];
		fin.getline(buffer, 100);
		//strchr在string里面寻找一个character，返回一个指针，位置在=符号的位置
		char *p = strchr(buffer, '=');
		*p = '\0';
		//拷贝strcpy
		strcpy(fruits[i].name, buffer);
		//atof把字符串转换成浮点数
		fruits[i].price = atof(p + 1);
	}
	fin.close();
	return true;
}


