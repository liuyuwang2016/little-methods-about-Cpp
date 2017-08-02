#include <iostream>
using namespace std;
const int N = 100000;
bool seive[N + 1];
int main() {

	for (int i = 2; i <= N; i++)
		seive[i] = true;
	for (int d = 2; d*d <= N; d++)
		if (seive[d])
			for (int n = d*d; n <= N; n += d)
				seive[n] = false;
	int sum = 0;
	for (int n = 2; n <= N; n++)
		if (seive[n])
			sum = sum + n;
	cout << sum << endl;
	return 0;
}
