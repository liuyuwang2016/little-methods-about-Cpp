#include <iostream>
using namespace std;
const int Normalize = 9; //����ͳһ�����±�

int Num;//������
int q[9];//8���ʺ���ռ�õ��к�
bool S[9];//��ǰ���Ƿ�ȫ��
bool L[17];//��Խ����Ƿ�ȫ
bool R[17];//�ҶԽ����Ƿ�ȫ

void Try(int col) {
	if (col == 9)
	{
		Num++;
		cout << "����" << Num << " : ";
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
	Try(1);//�ӵ�һ�п�ʼ�Żʺ�
	return 0;
}