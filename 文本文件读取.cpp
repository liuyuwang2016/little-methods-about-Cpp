#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin;
	fin.open("log.txt");
	while (!fin.eof())
	{
		int year, month, day, hour, minute, second;
		char tmp, id[20], operation[10];
		//获取文本文件中的一行
		fin >> year >> tmp >> month >> tmp >> day;
		fin >> hour >> tmp >> minute >> tmp >> second;
		fin >> id;
		fin >> operation;
		count++;
	}
	fin.close();
	cout << count << endl;
	return 0;
}
