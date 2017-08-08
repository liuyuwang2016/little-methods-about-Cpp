#include <iostream>
using namespace std;
const int Normalize = 9; //用来统一数组下标

int Num;//方案数
int q[9];//8个皇后所占用的行号
bool S[9];//当前行是否安全？
bool L[17];//左对角线是否安全
bool R[17];//右对角线是否安全

void Try(int col) {
	if (col == 9)
	{
		Num++;
		cout << "方案" << Num << " : ";
		for (int k = 0; k <= 8; k++)
			cout << q[k] << " ";
		cout << endl;
		return;
	}
	for (int row = 1; row <= 8; row++)
	{
		if (S[row] && R[col + row] && L[col - row + Normalize])
		{
			q[col] = row;
			S[row] = false;
			L[col - row + Normalize] = false;
			R[col + row] = false;
			//cout << "+++++++++++++++" << endl;
			Try(col + 1);
			S[row] = true;
			//cout << "---------------" << endl;
			L[col - row + Normalize] = true;
			R[col + row] = true;
		}
	}
}

int main() {
	Num = 0;
	for (int i = 0; i < 9; i++)
		S[i] = true;
	for (int i = 0; i < 17; i++)
	{
		L[i] = true;
		R[i] = true;
	}
	Try(1);//从第一列开始放皇后
	return 0;
}