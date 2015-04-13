#include "HeapSort.h"
#include <math.h>

HeapSort::HeapSort()
{

}

HeapSort::HeapSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

HeapSort::~HeapSort()
{

}

void HeapSort::sort()
{
	buildHeap();
	for (int i = 0; i < len; i++)
	{
		int hLen = len - i;
		// It is been done in buildHeap() when i =  0
		if (i != 0)
			adjustHeap(0, hLen);
		exchange(0, hLen - 1);
	}
}

void HeapSort::buildHeap()
{
	int n = 1;
	while (len > pow(2.0, n) - 1)
	{
		adjustHeap(0, len);
		n++;
	}
}

void HeapSort::adjustHeap(int start, int hLen)
{
	if (start >= hLen - 1)	return;

	int left = 2 * start + 1;
	int right = 2 * start + 2;

	// This also means left < hLen and
	// arr[left] and arr[right] exist.
	if (right < hLen)
	{
		// This means arr[start] is smaller than one of its child, so we just
		// need to find a larger child to replace it.
		if (arr[start] < arr[left] || arr[start] < arr[right])
		{
			if (arr[left] >= arr[right])
			{
				exchange(start, left);
			}
			else
			{
				exchange(start, right);
			}
		}
	}
	// This means left < hLen <= right and arr[right] does not exist.
	else if (left < hLen)
	{
		if (arr[start] < arr[left])
		{
			exchange(start, left);
		}
	}
	// This means hLen <= left, arr[left] does not exist and arr[start] has no child.
	// Actually, 'else' branch is not necessary as 'if (start >= hLen - 1)	return;'
	// at the beginning has ensured this.
	else
	{
		return;
	}

	adjustHeap(start + 1, hLen);
	adjustHeap(start + 2, hLen);
}


