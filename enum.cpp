#include <iostream>
using namespace std;
enum GameResult { WIN, LOSE, TIE, CANCEL };
int main() {
	GameResult result;
	enum GameResult omit = CANCEL;
	//枚举值可以进行关系运算，整数值赋值给枚举值需要进行强制类型转换
	for (int count = WIN; count <= CANCEL; count++) {
		result = GameResult(count);
		if (result == omit)
			cout << "The game was cancelled" << endl;
		else {
			cout << "The game was played" << endl;
			if (result == WIN)
				cout << " and we won!";
			if (result == LOSE)
				cout << " and we lost!";
			cout << endl;
		}
	}
	return 0;
}