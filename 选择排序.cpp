#include <iostream>
using namespace std;

int main() {
	int cards[13] = { 101, 112, 113, 107, 107, 108, 103, 104,
		109, 111,  102, 105, 110 };
	for (int i = 0; i < 13; i++)
	{
		int min = cards[i], min_id = i;
		for (int j = i + 1; j < 13; j++)
			if (cards[j] < min)
			{
				min = cards[j];
				min_id = j;
			}
		cards[min_id] = cards[i];
		cards[i] = min;
		cout << cards[i] << endl;
	}
	return 0;
}