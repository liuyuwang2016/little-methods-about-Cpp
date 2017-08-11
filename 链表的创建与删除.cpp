#include <iostream>
#include <fstream>
#include <cstring>
/*
����Ĵ�������
//��������һ��ͷָ��
Node *head = NULL;
//Ȼ����һ��whileѭ��
while (...)
{
Node * data = new Node;
//����һ������
//��ӵ���������
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
		//data��һ���ṹ���͵�ָ�룬 ����ڷ��������������͵�ʱ����ʹ��"."����Ҫʹ��"->";
		fin >> data->tm.year >> tmp >> data->tm.month >> tmp >> data->tm.day;
		fin >> data->tm.hour >> tmp >> data->tm.minute >> tmp >> data->tm.second;
		fin >> data->id;
		fin >> data->op;
		//��ӵ�����,������data����һ������ԭ����head��Ȼ���������data��head
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