#include "SelectionSort.h"
//#pragma comment(lib,"ws2_32.lib")

SelectionSort::SelectionSort()
{

}

SelectionSort::SelectionSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

SelectionSort::~SelectionSort()
{
	
}

void SelectionSort::sort()
{
	// 将a[i]和a[i+1..len]中最小的元素交换
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (less(arr[j], arr[min]))
			{
				min = j;
			}
		}
		exchange(i, min);
	}
}