#ifndef MERGESORT_H
#define MERGESORT_H

#include "Sorting.h"

class MergeSort : public Sorting
{
public:
	MergeSort();
	MergeSort(int * initArr, int initLen);
	virtual ~MergeSort();
	virtual void sort();
	
private:
	void mergesort(int low, int high);
	void merge(int low, int mid, int high);

};

#endif