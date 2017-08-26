// 自动售卖，从文件读入水果和价格，命令行参数指定语言 
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

struct LanguageMessages_t
{
	char menu[5][50];
	char fruit_file_error[50];
	char your_choice[30];
	char submenu[3][50];
	char submenu_left[5];
	char submenu_right[5];
	char submenu_buy[20];
	char submenu_payoff[20];
	char submenu_cancel[20];
	char submenu_price_unit[10];
	char submenu_weight_unit[10];
	char submenu_total_price[30];
	char submenu_input_weight[30];
	char submenu_have_bought[30];
} language;

void ShowMenu()
{
	for (int i = 0; i < 5; i++)
		cout << language.menu[i] << endl;
}

bool LoadLanguage(const char *file)
{
	ifstream fin(file);
	if (!file)
		return false;
	for (int i = 0; i < 5; i++)
		fin.getline(language.menu[i], 50);
	fin.getline(language.fruit_file_error, 50);
	fin.getline(language.your_choice, 30);
	for (int i = 0; i < 3; i++)
		fin.getline(language.submenu[i], 50);
	fin.getline(language.submenu_left, 5);
	fin.getline(language.submenu_right, 5);
	fin.getline(language.submenu_buy, 20);
	fin.getline(language.submenu_payoff, 20);
	fin.getline(language.submenu_cancel, 20);
	fin.getline(language.submenu_price_unit, 10);
	fin.getline(language.submenu_weight_unit, 10);
	fin.getline(language.submenu_total_price, 30);
	fin.getline(language.submenu_input_weight, 30);
	fin.getline(language.submenu_have_bought, 30);
	fin.close();
	return true;
}

int main(int argc, char *argv[])
{
	const char *file_lang = "Chs.txt";
	if (argc >= 2)      // 指定语言文件 
		file_lang = argv[1];
	if (!LoadLanguage(file_lang))
	{
		cout << "Language file error!" << endl;
		return 0;
	}

	Fruit_t *fruits = 0;
	int fruit_number;
	if (!GetFruits(fruits, fruit_number))
	{
		cout << language.fruit_file_error << endl;
		return 0;
	}

	while (1)
	{
		ShowMenu();
		cout << language.your_choice;
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
	cout << language.submenu[0] << endl;
	cout << language.submenu[1] << endl;
	for (int i = 0; i < fruit_number; i++)
	{
		cout << language.submenu_left << setw(2) << i + 1 << ". " << language.submenu_buy;
		cout << fruits[i].name << "(" << fixed << setw(5) << setprecision(2)
			<< fruits[i].price << language.submenu_price_unit << '/'
			<< language.submenu_weight_unit << ")";
		int len = strlen(language.submenu[0]) - strlen(language.submenu_left) - 4 - strlen(language.submenu_buy)
			- strlen(fruits[i].name) - 6 - strlen(language.submenu_price_unit) - 1
			- strlen(language.submenu_weight_unit) - 1 - strlen(language.submenu_right);
		for (int j = 0; j < len; j++)
			cout << ' ';
		cout << language.submenu_right << endl;
	}
	cout << language.submenu_left << setw(2) << fruit_number + 1 << ". "
		<< language.submenu_payoff;
	int len = strlen(language.submenu[0]) - strlen(language.submenu_left) - 4
		- strlen(language.submenu_payoff) - strlen(language.submenu_right);
	for (int j = 0; j < len; j++)
		cout << ' ';
	cout << language.submenu_right << endl;
	cout << language.submenu_left << setw(2) << fruit_number + 2 << ". "
		<< language.submenu_cancel;
	len = strlen(language.submenu[0]) - strlen(language.submenu_left) - 4
		- strlen(language.submenu_cancel) - strlen(language.submenu_right);
	for (int j = 0; j < len; j++)
		cout << ' ';
	cout << language.submenu_right << endl;
	cout << language.submenu[2] << endl;
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
		cout << language.submenu_total_price << fixed << setprecision(2) << setw(8) << sum
			<< language.submenu_price_unit << endl;
		cout << language.your_choice;
		int input = GetInteger();
		if (input > 0 && input <= fruit_number)
		{
			cout << language.submenu_input_weight;
			double w = GetDouble();
			sum += fruits[input - 1].price * w;
			weight[input - 1] += w;
		}
		else if (input == fruit_number + 1)
		{
			if (sum > 1E-6)    // 确实买了水果 
			{
				cout << language.submenu_have_bought;
				for (int i = 0; i < fruit_number; i++)
					if (fabs(weight[i]) > 1E-6)
						cout << weight[i] << language.submenu_weight_unit << fruits[i].name << ", ";
				cout << language.submenu_total_price << sum << language.submenu_price_unit << endl;
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
	if (!fin)
		return false;
	fin >> fruit_number;
	fin >> ws;
	fruits = new Fruit_t[fruit_number];
	for (int i = 0; i < fruit_number; i++)
	{
		char buffer[100];
		fin.getline(buffer, 100);
		char *p = strchr(buffer, '=');
		*p = '\0';
		strcpy(fruits[i].name, buffer);
		fruits[i].price = atof(p + 1);
	}
	fin.close();
	return true;
}
