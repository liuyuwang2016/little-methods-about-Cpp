#include <iostream>
using namespace std;

bool isPrime(int);

bool isPrime(int n)
{
	bool bPrime = true;
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			bPrime = false;
			break;
		}
	}
	return bPrime;
}

int main()
{
	for (int n = 2; n <= 100; n++)
	{
		if (isPrime(n))
			cout << n << endl;
	}
	return 0;
}