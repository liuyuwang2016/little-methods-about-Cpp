#include <iostream>
using namespace std;

int insertionSort(int[], int);

int main() {
	int *ptr;
	int size;
	cout << "Please input the array size: ";
	cin >> size;

	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> *(ptr + i);
	}

	cout << "Before insertion sort: " << endl;
	for (int j = 0; j < size; j++)
	{
		cout << *(ptr + j) << " ";
	}
	insertionSort(ptr, size);
	cout << "After insertion sort: " << endl;
	for (int k = 0; k < size; k++)
	{
		cout << *(ptr + k) << " ";
	}
	system("pause");
	return 0;
}

int insertionSort(int a[], int arraysize)
{
	int temp = 0;
	int next = 0;
	for (int i = 1; i < arraysize; i++)
	{
		/*The value of not been sorted yet*/
		temp = a[i];
		/*The last value of been sorted yet*/
		next = i;
		while ((next > 0) && (a[next - 1] > temp))
		{
			a[next] = a[next - 1];
			next--;
		}
		a[next] = temp;
	}
	return *a;
}