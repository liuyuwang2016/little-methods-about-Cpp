#include <iostream>
using namespace std;
/*在考虑工作之前，首先要想一想工作会以一个什么样的形式结束*/
int Num; //方案数量
int take[5]; // 5本书分别给谁（用户编号）
bool assigned[5]; //5本书是否分配出去
int like[5][5] = { { 0,0,1,1,0 },
{ 1,1,0,0,1 },
{ 0,1,1,0,1 },
{ 0,0,0,1,0 },
{ 0,1,0,0,1 } };

void Try(int id)
{
	//递归终止条件：所有读者都已经分配到适合的书籍
	if (id == 5)
	{
		//方案数加1
		Num++;
		//输出每一个方案的具体细节
		cout << "第" << Num << "个方案（按ABCDE次序）： ";
		for (int i = 0; i < 5; i++)
			cout << take[i] << ' ';
		cout << endl;
		return;
	}
	//逐一为每本书找到适合的读者
	for (int book = 0; book <= 4; book++)
	{
		//是否满足分书的条件
		if ((like[id][book]) == 1 && !assigned[book])
		{
			//记录当前这本书的分配状

			take[id] = book;
			assigned[book] = true;
			//为下一个读者分配适合的书
			//先从这里把所有的完成，之后再进行assigned[book] = false;的过程
			Try(id + 1);
			//将书退还回溯，尝试另一种方案
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
