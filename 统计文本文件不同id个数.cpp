#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	ifstream fin("log.txt");
	int count = 0;
	char ids[600][20];
	while (!fin.eof())
	{
		int year, month, day, hour, minute, second;
		char tmp, id[20], operation[10];

		fin >> year >> tmp >> month >> tmp >> day;
		fin >> hour >> tmp >> minute >> tmp >> second;
		fin >> id;
		fin >> operation;

		int user_count = 0;
		int found = -1;

		for (int i = 0; i < user_count; i++)
			if (strcmp(ids[i], ids[j]) == 0)
			{
				found = j;
				break;
			}
		if (found == -1)
		{
			strcpy(ids[user_count], id);
			user_count++;
		}


	}
	fin.close();


	cout << user_count << endl;
	return 0;
}
