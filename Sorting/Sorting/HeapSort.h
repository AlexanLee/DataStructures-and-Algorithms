#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Sorting.h"

class HeapSort : public Sorting
{
public:
	HeapSort();
	HeapSort(int * initArr, int initLen);
	virtual ~HeapSort();
	virtual void sort();

private:
	void adjustHeap(int start, int end);
	void buildHeap();
	
};

#endif





