#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sorting.h"

class BubbleSort : public Sorting
{
public:
	BubbleSort();
	BubbleSort(int * initArr, int initLen);
	virtual ~BubbleSort();
	virtual void sort();
};

#endif