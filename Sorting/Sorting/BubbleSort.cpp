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
	// һһ�Ƚ�a[j]��a[j+1]����a[j]>a[j+1]ʱ����Ԫ�ؽ���
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