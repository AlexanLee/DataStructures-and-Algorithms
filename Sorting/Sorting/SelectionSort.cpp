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
	// ��a[i]��a[i+1..len]����С��Ԫ�ؽ���
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