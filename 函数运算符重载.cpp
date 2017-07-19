#include <iostream>
using namespace std;

class Less
{
	int thres_;
public:
	Less(int th) : thres_(th) {}
	bool operator() (int);
};

bool Less::operator()(int value)
{
	return (value < thres_);
}

void Filter(int * array, int num, Less fn)
{
	for (int i = 0; i < num; i++)
		if (fn(array[i])) cout << array[i] << ' ';
	cout << endl;
}

int main()
{
	int array[5] = { 1, -4, 10, 0, -1 };
	int thres;
	cout << "thres:";
	cin >> thres;
	Less less_than(thres);
	Filter(array, 5, less_than);
	return 0;
}