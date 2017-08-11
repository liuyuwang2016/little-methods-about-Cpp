#include <iostream>
#include <fstream>
#include <cstring>
/*�������������������ƽ�������أ��û����-->��ϣ�㷨-->����*/
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

void Insert(Node *hash_tab[], Node elem)
{
	//�����û���ŵĹ�ϣֵ
	int idx = Hash(elem.id);

	//����½ڵ㵽����ͷ����Ϊ�µ�ͷ��㣩
	Node * data = new Node;
	*data = elem;
	data->next = hash_tab[idx];
	hash_tab[idx] = data;
}
void Print(Node *list)
{

}
void Delete(Node *list)
{
	while (list)
	{
		Node* tmp = list;
		list = list->next;
		delete tmp;
	}
}

void Release(Node *hash_tab[])
{
	for (int i = 0; i < 256; i++)
	{
		if (hash_tab[i] == NULL)
			continue;
		Delete(hash_tab[i]);
		hash_tab[i] = NULL;
	}
}

void Output(Node *hash_tab[])
{
	for (int i = 0; i < 256; i++)
	{
		if (hash_tab[i] == NULL)
			continue;
		cout << i << ": ";
		Print(hash_tab[i]);
		cout << endl << endl;
	}
}


int main() {
	Node* list_tab[256] = { NULL };
	ifstream fin("log.txt");
	while (!fin.eof())
	{
		char tmp;
		Node data;
		fin >> data.tm.year >> tmp >> data.tm.month >> tmp >> data.tm.day;
		fin >> data.tm.hour >> tmp >> data.tm.minute >> tmp >> data.tm.second;
		fin >> data.id;
		fin >> data.op;
		Insert(list_tab, data);
	}
	fin.close();
	Output(list_tab);
	Release(list_tab);
	return 0;
}

