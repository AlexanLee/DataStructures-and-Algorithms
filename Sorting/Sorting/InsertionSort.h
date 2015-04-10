#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sorting.h"

class InsertionSort : public Sorting
{
public:
	InsertionSort();
	InsertionSort(int * initArr, int initLen);
	virtual ~InsertionSort();
	virtual void sort();
};

#endif