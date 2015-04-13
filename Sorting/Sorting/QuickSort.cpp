#include "QuickSort.h"
#include <cassert>

QuickSort::QuickSort()
{

}

QuickSort::QuickSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

QuickSort::~QuickSort()
{

}

void QuickSort::sort()
{
	sort(0, len - 1);
}

void QuickSort::sort(int low, int high)
{
	if (high <= low)	return;
	int j = partition(low, high);
	sort(low, j - 1);
	sort(j + 1, high);
}

int QuickSort::partition(int low, int high)
{
	int i = low, j = high;
	int temp = arr[low];	// �� arr[low] ���ǵ�һ����
	while (i < j)
	{
		// ����������С�� temp �������� arr[i]
		while (i < j && less(temp, arr[j]))
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		// ���������Ҵ��ڻ���� temp �������� arr[j]
		while (i < j && less(arr[i], temp))
		{
			i++;
		}
		if (i < j)
		{
			arr[j] = arr[i];
			j--;
		}

	}
	//�˳�ʱ��i����j���� temp �������С�
	arr[j] = temp;

	return j;
}
