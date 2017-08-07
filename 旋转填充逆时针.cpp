#include <iostream>
#include <iomanip> //std::setw
using namespace std;
const int N = 20;
void FillMatrix(int matrix[N][N], int size, int num, int offset)
{
	if (size == 0)
		return;
	if (size == 1)
	{
		matrix[offset][offset] = num;
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		matrix[offset + i][offset] = num - i;
		matrix[offset + size - 1][offset + i] = num - (size - 1) + i;
		matrix[offset + size - 1 - i][offset + size - 1] = num - 2 * (size - 1) + i;
		matrix[offset][offset + size - 1 - i] = num - 3 * (size - 1) + i;
	}
	FillMatrix(matrix, size - 2, num - 4 * (size - 1), offset + 1);
}

int main() {
	int Matrix[N][N];
	int n;
	cin >> n;
	FillMatrix(Matrix, n, n*n, 0);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(2) << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}