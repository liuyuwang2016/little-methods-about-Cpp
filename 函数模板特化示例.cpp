#include <iostream>
#include <string>
using namespace std;

template <typename T>
T sum(T a, T b)
{
	return a + b;
}

template<>
char* sum(char* a, char* b)
{
	//strlen()�ش��ַ����ĳ���
	char* p = new char[strlen(a) + strlen(b) + 1];
	//strcpy����
	strcpy(p, a);
	//strcat�ϲ�
	strcat(p, b);
	return p;
}

int main() {
	cout << sum(3, 4) << ' ' << sum(5.1, 13.8) << endl;
	char *str1 = "Hello, ", *str2 = "world";
	cout << sum(str1, str2) << endl;
	return 0;
}