#include "CountingSort.h"
#include <iostream>
using namespace std;

CountingSort::CountingSort()
{
	for (int i = 0; i < MAX; i++)
	{
		TEMP[i] = 0;
	}
}

CountingSort::CountingSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{
	for (int i = 0; i < MAX; i++)
	{
		TEMP[i] = 0;
	}
}

CountingSort::~CountingSort()
{

}

void CountingSort::sort()
{
	int * outArr = new int[len];

	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= MAX)
		{
			cout << "Out of range!" << endl;
			return;
		}
		TEMP[arr[i]] += 1;
	}
	// TEMP[i] now contains the number of elements equal to arr[i];

	for (int i = 1; i < MAX; i++)
	{
		TEMP[i] += TEMP[i - 1];
	}
	// TEMP[i] now contains the number of elements less than or equal to arr[i].

	for (int i = len - 1; i > -1; i--)
	{
		outArr[TEMP[arr[i]] - 1] = arr[i];
		TEMP[arr[i]]--;
	}

	for (int i = 0; i < len; i++)
	{
		arr[i] = outArr[i];
	}

	delete outArr;
}