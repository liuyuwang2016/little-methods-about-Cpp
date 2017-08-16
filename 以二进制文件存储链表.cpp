#include <iostream>
#include <fstream>
using namespace std;
struct Time_t
{
	int year, month, day;
	int hour, minute, second;
};

struct Log_info
{
	Time_t tm;
	char id[20];
	char op[10];
};

struct Node {
	Log_info log;
	Node* next;
};

int main() {
	Output(list_tab);
	SaveHashTab(list_tab, "list.tab");
	Release(list_tab);
	LoadHashTab(list_tab, "list.tab");
	Output(list_tab);
	Release(list_tab);
	return 0;
}

void SaveHashTab(Node *hash_tab[], const char *filename)
{
	ofstream fout(filename, ios::binary);
	for (int i = 0; i < 256; i++)
	{
		Node *p = hash_tab[i];
		while (p)
		{
			fout.write((char*)&(p->log), sizeof(p->log));
			p = p->next;
		}
	}
	fout.close();
}

void LoadHashTab(Node* hash_tab[], const char *filename)
{
	ifstream fin(filename, ios::binary);
	while (fin)
	{
		Node data;
		fin.read((char*) &(data.log), sizeof(data.log));
		if (fin.eof())
			break;
		Insert(hash_tab, data);
	}
	fin.close();
}