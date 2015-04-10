#ifndef SORTING_H
#define SORTING_H

class Sorting
{
public:
	Sorting();
	Sorting(int * initArr, int initLen);
	virtual ~Sorting();
	virtual void sort();	// Default : in ascending order
	virtual bool less(int a, int b);
	virtual void exchange(int i, int j);
	virtual void show();
	virtual bool isSorted();

public:
	int * arr;
	int len;
};

#endif