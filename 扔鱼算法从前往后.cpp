#include <iostream>
using namespace std;

int main() {
	int num[5];
	for (num[0] = 1;; num[0]++)
	{
		if (num[0] % 5 != 1)
			continue;
		int i;
		for (i = 1; i <= 4; i++)
		{
			num[i] = (num[i - 1] - 1) / 5 * 4;
			if (num[i] % 5 != 1)
				break;
		}
		if (i <= 4)
			continue;
		break;
	}
	for (int i = 0; i < 5; i++)
		cout << num[i] << ' ';
	return 0;
}