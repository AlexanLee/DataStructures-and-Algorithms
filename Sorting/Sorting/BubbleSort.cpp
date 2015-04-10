#include "BubbleSort.h"
#pragma comment(lib,"ws2_32.lib")

BubbleSort::BubbleSort()
{

}

BubbleSort::BubbleSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

BubbleSort::~BubbleSort()
{

}

void BubbleSort::sort()
{
	// 一一比较a[j]和a[j+1]并当a[j]>a[j+1]时进行元素交换
	for (int i = len - 1; i > -1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (!less(arr[j], arr[j+1]))
			{
				exchange(j, j + 1);
			}
		}
	}
}