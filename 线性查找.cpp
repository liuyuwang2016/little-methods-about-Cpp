#include <iostream>
using namespace std;

int main() {
	int cards[13] = { 101, 113, 303, 206, 405, 208, 311, 304, 410, 309, 112, 207, 402 };
	int pos = -1;
	for (int i = 0; i < 13; i++)
		if (cards[i] == 112)
		{
			pos = i;
			break;
		}
	if (pos != -1)
		cout << "黑桃Q是第" << pos + 1 << "张" << endl;
	else
		cout << "没找到" << endl;
	return 0;
}