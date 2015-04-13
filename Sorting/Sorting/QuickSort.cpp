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
	int temp = arr[low];	// 即 arr[low] 就是第一个坑
	while (i < j)
	{
		// 从右向左找小于 temp 的数来填 arr[i]
		while (i < j && less(temp, arr[j]))
		{
			j--;
		}
		if (i < j)
		{
			arr[i] = arr[j];
			i++;
		}

		// 从左向右找大于或等于 temp 的数来填 arr[j]
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
	//退出时，i等于j。将 temp 填到这个坑中。
	arr[j] = temp;

	return j;
}
