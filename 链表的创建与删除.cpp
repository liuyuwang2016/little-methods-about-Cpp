#include <iostream>
#include <fstream>
#include <cstring>
/*
链表的创建过程
//首先生成一个头指针
Node *head = NULL;
//然后是一个while循环
while (...)
{
Node * data = new Node;
//读入一行数据
//添加到链表。。。
data->next = head;
head = data;
}*/
using namespace std;
struct Time_t
{
	int year, month, day;
	int hour, minute, second;
};

struct Node {
	Time_t tm;
	char id[20];
	//operation: LOGIN & LOGOUT
	char op[20];
	Node* next;
};




int main() {
	ifstream fin("log.txt");
	Node *head = NULL;
	//eof means end of file
	while (!fin.eof())
	{

		char tmp;
		Node * data = new Node;
		//data是一个结构类型的指针， 因此在访问他的数据类型的时候不能使用"."而是要使用"->";
		fin >> data->tm.year >> tmp >> data->tm.month >> tmp >> data->tm.day;
		fin >> data->tm.hour >> tmp >> data->tm.minute >> tmp >> data->tm.second;
		fin >> data->id;
		fin >> data->op;
		//添加到链表,首先让data的下一个接上原来的head，然后把新来的data给head
		data->next = head;
		head = data;
	}
	fin.close();
	return 0;
}

int TimeDifference(Time_t s, Time_t t) {
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day_count = t.day - s.day;
	for (int i = s.month; i <= t.month; i++)
		day_count += days[i - 1];
	int result = day_count * 60 * 60 * 24;
	result += (t.hour - s.hour) * 60 * 60;
	result += (t.minute - s.minute) * 60;
	result += (t.second - s.second);
	return result;
}