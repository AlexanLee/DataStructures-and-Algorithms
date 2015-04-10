#include "InsertionSort.h"

InsertionSort::InsertionSort()
{

}

InsertionSort::InsertionSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

InsertionSort::~InsertionSort()
{

}

void InsertionSort::sort()
{
	for (int i = 1; i < len; i++)
	{
		// 将a[i]插入到a[i-1]、a[i-2]、a[i-3]...之中
		for (int j = i; j > 0 && less(arr[j], arr[j - 1]);j--)
		{
			exchange(j, j - 1);
		}
	}
}

