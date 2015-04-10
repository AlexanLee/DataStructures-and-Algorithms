#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sorting.h"

class SelectionSort : public Sorting
{
public:
	SelectionSort();
	SelectionSort(int * initArr, int initLen);
	virtual ~SelectionSort();
	virtual void sort();
};

#endif