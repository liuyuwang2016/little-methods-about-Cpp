#include <iostream>
#include <string>
using namespace std;

char week_name[7][4] = { "mon","tu","wed","thu","fri","sat","sun" };

class WeekTemp {
	int temp[7];
public:
	int& operator[] (const char* name)
	{
		for (auto i = 0; i < 7; i++) {
			//strcmp�Ƚ��ַ����Ƿ���ȣ���ȵĻ��ͻش�0
			if (strcmp(week_name[i], name) == 0)
				return temp[i];
		}
	}
};
int main()
{
	WeekTemp beijing;
	beijing["mon"] = -3;
	beijing["tu"] = -1;
	cout << "Monday Temperature: " << beijing["mon"] << endl;
	return 0;
}