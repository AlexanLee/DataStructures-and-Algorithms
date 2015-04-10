#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "InsertionSort.h"

class ShellSort : public InsertionSort
{
public:
	ShellSort();
	ShellSort(int * initArr, int initLen);
	virtual ~ShellSort();
	virtual void sort();
};

#endif