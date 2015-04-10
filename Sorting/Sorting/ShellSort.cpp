#include "ShellSort.h"

ShellSort::ShellSort()
{

}

ShellSort::ShellSort(int * initArr, int initLen) : InsertionSort(initArr, initLen)
{

}

ShellSort::~ShellSort()
{

}


void ShellSort::sort()
{
	for (int step = len / 2; step > 0; step /= 2)
	{
		for (int i = step; i < len; i++)
		{
			// ��a[i]���뵽a[i-step]��a[i-2*step]��a[i-3*step]...֮��
			for (int k = i; k >= step && less(arr[k], arr[k - step]); k -= step)
			{
				exchange(k, k - step);
			}
		}
	}
}

