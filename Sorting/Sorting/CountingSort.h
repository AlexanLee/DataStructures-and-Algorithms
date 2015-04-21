#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include "Sorting.h"

const int MAX = 1024;

class CountingSort : public Sorting
{
public:
	CountingSort();
	CountingSort(int * initArr, int initLen);
	virtual ~CountingSort();
	virtual void sort();

private:
	int TEMP[MAX];

};


#endif