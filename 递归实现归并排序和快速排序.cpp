#include <iostream>
using namespace std;
/*�ݹ�ʵ�ֹ鲢�����Ȱ����������һ��Ϊ����Ȼ����������һ����ѧ���ɷ���˼��*/
void MergeSort(int *array, int start, int end)
{
	//�ݹ����ֹ����
	if (start == end - 1)
		return;
	//��������������ֿ�����
	int mid = (end + start) / 2;
	MergeSort(array, start, mid);
	MergeSort(array, mid, end);
	//������ʱ�ռ��źϲ�Ԫ��
	int * tmp = new int[end - start];
	//����ȡ���������Ԫ�أ����кϲ�
	int left_idx = start, right_idx = mid, i = 0;
	/*��ߵ�������ұߵ����鶼����Ԫ�أ�û��Ū���ʱ�������һ��*/
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
	//����ʱ�ռ临�Ʒ���������
	for (int i = 0, idx = start; i < end - start; i++, idx++)
		array[idx] = tmp[i];
	delete[] tmp;
}

/*���������Ե�һ��Ԫ��Ϊ���գ��ȽϺ����Ԫ�ر������Ǳ���С��Ȼ����С�Ķ�ȥ��ߣ����ô�Ķ�ȥ�ұ�*/
void QuickSort(int * array, int len)
{
	if (len <= 1)
		return;
	//����Ŀ���Ϊ�������������ռ�
	int *left = new int[len], *right = new int[len];
	//�������������鳤�ȵĳ�ֵ��Ϊ�㣩
	int left_idx = 0, right_idx = 0;
	//���
	int key = array[0];
	for (int i = 1; i < len; i++)
	{
		//�������е�������ͬ
		if (array[i] < key)
			left[left_idx++] = array[i];
		if (array[i] > key)
			right[right_idx++] = array[i];
	}
	//���������������
	QuickSort(left, left_idx);
	QuickSort(right, right_idx);
	//�ϲ�������
	int idx = 0;
	for (int i = 0; i < left_idx; i++)
		array[idx++] = left[i];
	//��������������֮��
	array[idx++] = key;
	for (int i = 0; i < right_idx; i++)
		array[idx++] = right[i];
	//�ͷſռ�
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