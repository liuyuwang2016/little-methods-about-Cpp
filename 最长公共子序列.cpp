#include <iostream>
using namespace std;
//?how to get a accurate size of M & N
int lcs[M][N];
int decision[M][N];
enum {
	I_J,
	I_1,
	J_1
};
int m = strlen(A);
int n = strlen(B);
int main() {
	//设定递推初值
	for (int j = 0; j < n + 1; j++)
		lcs[m][j] = 0;
	for (int i = 0; i < m + 1; i++)
		lcs[i][n] = 0;
	for (int i = m - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			if (A[i] == B[j])
			{
				lcs[i][j] = 1 + lcs[i + 1][j + 1];
				decision[i][j] = I_J;
			}
			else if (lcs[i][j + 1] < lcs[i + 1][j])
			{
				lcs[i][j] = lcs[i + 1][j];
				decision[i][j] = I_1;
			}
			else
			{
				lcs[i][j] = lcs[i][j + 1];
				decision[i][j] = J_1;
			}
	for (int i = 0, j = 0; i < m && j < n;)
		switch (decision[i][j])
		{
		case I_J:
			cout << A[i];
			i++;
			j++;
			break;
		case I_1:
			i++;
			break;
		case J_1:
			j++;
			break;
		}
}