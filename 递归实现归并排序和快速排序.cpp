#include <iostream>
using namespace std;
/*递归实现归并排序，先把无序的数组一分为二，然后两边排序。一个数学归纳法的思想*/
void MergeSort(int *array, int start, int end)
{
	//递归的终止条件
	if (start == end - 1)
		return;
	//对于两个子数组分开排序
	int mid = (end + start) / 2;
	MergeSort(array, start, mid);
	MergeSort(array, mid, end);
	//分配临时空间存放合并元素
	int * tmp = new int[end - start];
	//依次取出子数组的元素，进行合并
	int left_idx = start, right_idx = mid, i = 0;
	/*左边的数组和右边的数组都还有元素，没有弄完的时候进行下一步*/
	while (left_idx < mid && right_idx < end)
	{
		if (array[left_idx] < array[right_idx])
			tmp[i++] = array[left_idx++];
		else
			tmp[i++] = array[right_idx++];
	}
	while (left_idx < mid)
		tmp[i++] = array[left_idx++];
	while (right_idx < end)
		tmp[i++] = array[right_idx++];
	//从临时空间复制返回数组中
	for (int i = 0, idx = start; i < end - start; i++, idx++)
		array[idx] = tmp[i];
	delete[] tmp;
}

/*快速排序，以第一个元素为参照，比较后面的元素比他大还是比他小，然后让小的都去左边，再让大的都去右边*/
void QuickSort(int * array, int len)
{
	if (len <= 1)
		return;
	//按最坏的可能为两个子数组分配空间
	int *left = new int[len], *right = new int[len];
	//设置两个子数组长度的初值（为零）
	int left_idx = 0, right_idx = 0;
	//拆分
	int key = array[0];
	for (int i = 1; i < len; i++)
	{
		//假设所有的数不相同
		if (array[i] < key)
			left[left_idx++] = array[i];
		if (array[i] > key)
			right[right_idx++] = array[i];
	}
	//对子数组进行排序
	QuickSort(left, left_idx);
	QuickSort(right, right_idx);
	//合并子数组
	int idx = 0;
	for (int i = 0; i < left_idx; i++)
		array[idx++] = left[i];
	//放在这两个数组之间
	array[idx++] = key;
	for (int i = 0; i < right_idx; i++)
		array[idx++] = right[i];
	//释放空间
	delete[] left;
	delete[] right;
}

int main() {
	int cards[13] = { 101, 112, 113, 107, 115, 108, 103, 104,
		109, 111,  102, 105, 110 };
	//QuickSort(cards, 13);
	MergeSort(cards, 0, 13);
	for (int i = 0; i < 13; i++)
		cout << cards[i] << " ";
	cout << endl;
	return 0;
}