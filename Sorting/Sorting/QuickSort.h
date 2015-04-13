#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sorting.h"

class QuickSort : public Sorting
{
public:
	QuickSort();
	QuickSort(int * initArr, int initLen);
	virtual ~QuickSort();
	virtual void sort();

private:
	void sort(int low, int high);
	int partition(int low, int high);

};

#endif