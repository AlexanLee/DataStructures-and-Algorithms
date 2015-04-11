
// Blog:http://www.cnblogs.com/xiehongfeng100/p/4418638.html

#include "MergeSort.h"
#include <cassert>
#include <iostream>
using namespace std;

MergeSort::MergeSort()
{

}

MergeSort::MergeSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

MergeSort::~MergeSort()
{

}

void MergeSort::sort()
{
	mergesort(0, len - 1);
}

// Optimization with memory allocation
// driver function
//void MergeSort::sort()
//{
//	// allocation once
//	int* pTmpBuf = new(nothrow) int[len];
//	assert(pTmpBuf != nullptr);
//	mergesort(pTmpBuf, 0, len - 1);
//	delete[] pTmpBuf;
//}

void MergeSort::mergesort(int low, int high)
{
	if (high <= low)	return;

	int mid = (low + high) / 2;
	mergesort(low, mid);
	mergesort(mid + 1, high);
	merge(low, mid, high);
}

// Nomal version
void MergeSort::merge(int low, int mid, int high)
{
	int numOfArr = high - low + 1;
	int * copyOfArr = new(nothrow) int[numOfArr];
	assert(copyOfArr != nullptr);

	// Copy
	for (int k = 0; k < numOfArr; k++)
		copyOfArr[k] = arr[low + k];

	// Merge
	int i = low;
	int j = mid + 1;
	for (int k = low; k < high + 1; k++)
	{
		if (i > mid)
		{
			arr[k] = copyOfArr[j - low];
			j++;
		}
		else if (j > high)
		{
			arr[k] = copyOfArr[i - low];
			i++;
		}
		else if (less(copyOfArr[j - low], copyOfArr[i - low]))
		{
			arr[k] = copyOfArr[j - low];
			j++;
		}
		else
		{
			arr[k] = copyOfArr[i - low];
			i++;
		}
	}

	delete[] copyOfArr;
}


// Detailed version
//void MergeSort::merge(int low, int mid, int high)
//{
//	int nOfLeft = mid - low + 1;
//	int nOfRight = high - mid;
//	int * copyOfLeft = new(nothrow) int[nOfLeft];
//	int * copyOfRight = new(nothrow) int[nOfRight];
//	assert(copyOfLeft != nullptr);
//	assert(copyOfRight != nullptr);
//
//	// Copy left part
//	int i;
//	for (i = 0; i < nOfLeft; i++)
//	{
//		copyOfLeft[i] = arr[i + low];
//	}
//
//	// Copy right part
//	int j;
//	for (j = 0; j < nOfRight; j++)
//	{
//		copyOfRight[j] = arr[j + mid + 1];
//	}
//
//	// 在这里需要意识到的一个问题：copyOfLeft及copyOfRight已经是“有序”序列
//	// Merge
//	i = 0;
//	j = 0;
//	for (int k = low; k < high + 1; k++)
//	{
//		if (i > nOfLeft - 1)
//		{
//			arr[k] = copyOfRight[j];
//			j++;
//		}
//		else if (j > nOfRight - 1)
//		{
//			arr[k] = copyOfLeft[i];
//			i++;
//		}
//		else if (less(copyOfLeft[i], copyOfRight[j]))
//		{
//			arr[k] = copyOfLeft[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = copyOfRight[j];
//			j++;
//		}
//	}
//
//	delete[] copyOfLeft;
//	delete[] copyOfRight;
// }


// Optimization with Insertion Sort
//void MergeSort::merge(int low, int mid, int high)
//{
//	if (high -low < 20)	// Insertion Sort
//	{
//		for (int i = low + 1; i < high + 1; i++)
//		{
//			for (int j = i; j > 0 && less(arr[j], arr[j - 1]); j--)
//			{
//				exchange(j, j - 1);
//			}
//		}
//	}
//	else	// Original Merging
//	{
//		int numOfArr = high - low + 1;
//		int * copyOfArr = new(nothrow) int[numOfArr];
//		assert(copyOfArr != nullptr);
//
//		// Copy
//		for (int k = 0; k < numOfArr; k++)
//			copyOfArr[k] = arr[low + k];
//
//		// Merge
//		int i = low;
//		int j = mid + 1;
//		for (int k = low; k < high + 1; k++)
//		{
//			if (i > mid)
//			{
//				arr[k] = copyOfArr[j - low];
//				j++;
//			}
//			else if (j > high)
//			{
//				arr[k] = copyOfArr[i - low];
//				i++;
//			}
//			else if (less(copyOfArr[j - low], copyOfArr[i - low]))
//			{
//				arr[k] = copyOfArr[j - low];
//				j++;
//			}
//			else
//			{
//				arr[k] = copyOfArr[i - low];
//				i++;
//			}
//		}
//
//		delete[] copyOfArr;
//	}
//}



