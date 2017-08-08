#include <iostream>
using namespace std;

int main() {
	int num[5];
	for (num[4] = 6;; num[4] += 5)
	{
		int i = 4;
		for (; i >= 1; i--)
		{
			if (num[i] % 4 != 0)
				break;
			num[i - 1] = num[i] / 4 * 5 + 1;
		}
		if (i >= 1)
			continue;
		break;
	}
	for (int i = 0; i < 5; i++)
		cout << num[i] << ' ';
	return 0;
}