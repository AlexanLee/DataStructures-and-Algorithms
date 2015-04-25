#include "RadixSort.h"
#include <math.h>

RadixSort::RadixSort()
{

}

RadixSort::RadixSort(int * initArr, int initLen) : Sorting(initArr, initLen)
{

}

RadixSort::~RadixSort()
{

}

void RadixSort::sort()
{
	for (int d = 0; d < MAXDIGITS; d++)
	{
		for (int i = 1; i < len; i++)
		{
			for (int j = i; j > 0 && less(getDigit(arr[j], d), getDigit(arr[j - 1], d)); j--)
			{
				exchange(j, j - 1);
			}
		}
	}
}

int RadixSort::getDigit(int data, int digit)
{
	int temp;
	temp = data;
	while (digit)
	{
	    temp /= 10;
		digit--;
	}
	return (temp % 10);
}

int RadixSort::getDigitNum(int data)
{
	int digitNum = 0;
	while (data)
	{
		digitNum++;
		data = data / 10;
	}
	return digitNum;
}