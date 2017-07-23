#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Sum {
	T a, b;
public:
	Sum(T op1, T op2) : a(op1), b(op2) {}
	T DoIt() { return a + b; }
};

template<>
class Sum<char*> {
	char *str1, *str2;
public:
	Sum(char* s1, char* s2) :str1(s1), str2(s2) {}
	char* DoIt() {
		char* tmp = new char[strlen(str1) + strlen(str2) + 1];
		strcpy(tmp, str1);
		strcat(tmp, str2);
		return tmp;
	}
};

int main()
{
	Sum<int> obj1(3, 4);
	cout << obj1.DoIt() << endl;

	char *s1 = "Hello, ", *s2 = "THU";
	Sum<char*> obj2(s1, s2);
	cout << obj2.DoIt() << endl;
	return 0;
}