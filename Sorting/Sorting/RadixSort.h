#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "Sorting.h"

const int MAXDIGITS = 3;	// ��ࡰʮλ����

class RadixSort : public Sorting
{
public:
	RadixSort();
	RadixSort(int * initArr, int initLen);
	virtual ~RadixSort();
	virtual void sort();

private:
	int getDigit(int data, int digit);
	int getDigitNum(int data);

};


#endif