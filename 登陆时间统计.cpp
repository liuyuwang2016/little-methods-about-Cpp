#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Time_t
{
	int year, month, day;
	int hour, minute, second;
};

int TimeDifference(Time_t, Time_t);

int main() {
	ifstream fin("log.txt");
	int user_count = 0;
	char ids[600][20];
	bool online[600];
	Time_t last_on[600];
	int secs[600];
	//eof means end of file
	while (!fin.eof())
	{
		Time_t t;
		char tmp, id[20], operation[10];

		fin >> t.year >> tmp >> t.month >> tmp >> t.day;
		fin >> t.hour >> tmp >> t.minute >> tmp >> t.second;
		fin >> id;
		fin >> operation;

		int found = -1;
		for (int i = 0; i < user_count; i++)
			if (strcmp(id, ids[i]) == 0)
			{
				found = i;
				break;
			}
		if (found == -1)
		{
			strcpy(ids[user_count], id);
			if (strcmp(operation, "LOGIN") == 0)
			{
				online[user_count] = true;
				last_on[user_count] = t;
			}
			else
				online[user_count] = false;
			user_count++;
		}
		else
		{
			if (strcmp(operation, "LOGIN") == 0)
			{
				if (!online[found])
				{
					online[found] = true;
					last_on[found] = t;
				}
			}
			else
			{
				if (online[found])
				{
					online[found] = false;
					secs[found] += TimeDifference(last_on[found], t);
				}
			}
		}
	}
	fin.close();
	ofstream  fout("times.txt");
	for (int i = 0; i < user_count; i++)
		fout << ids[i] << " " << secs[i] << endl;
	fout.close();
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