#include <iostream>
using namespace std;
/*�ڿ��ǹ���֮ǰ������Ҫ��һ�빤������һ��ʲô������ʽ����*/
int Num; //��������
int take[5]; // 5����ֱ��˭���û���ţ�
bool assigned[5]; //5�����Ƿ�����ȥ
int like[5][5] = { { 0,0,1,1,0 },
{ 1,1,0,0,1 },
{ 0,1,1,0,1 },
{ 0,0,0,1,0 },
{ 0,1,0,0,1 } };

void Try(int id)
{
	//�ݹ���ֹ���������ж��߶��Ѿ����䵽�ʺϵ��鼮
	if (id == 5)
	{
		//��������1
		Num++;
		//���ÿһ�������ľ���ϸ��
		cout << "��" << Num << "����������ABCDE���򣩣� ";
		for (int i = 0; i < 5; i++)
			cout << take[i] << ' ';
		cout << endl;
		return;
	}
	//��һΪÿ�����ҵ��ʺϵĶ���
	for (int book = 0; book <= 4; book++)
	{
		//�Ƿ�������������
		if ((like[id][book]) == 1 && !assigned[book])
		{
			//��¼��ǰ�Ȿ��ķ���״

			take[id] = book;
			assigned[book] = true;
			//Ϊ��һ�����߷����ʺϵ���
			//�ȴ���������е���ɣ�֮���ٽ���assigned[book] = false;�Ĺ���
			Try(id + 1);
			//�����˻����ݣ�������һ�ַ���
			//cout << "--------------------" << endl;
			assigned[book] = false;
		}
	}
}


int main() {
	Num = 0;
	for (int book = 0; book < 5; book++)
		assigned[book] = false;
	Try(0);
	return 0;
}
