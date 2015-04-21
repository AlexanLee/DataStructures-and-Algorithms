#ifndef BUCKETSORT_H
#define BUCKETSORT_H

class BucketSort
{
public:
	BucketSort();
	BucketSort(float * initArr, int initLen);
	virtual ~BucketSort();
	virtual void sort();
	virtual void show();
	virtual bool isSorted();

public:
	float * arr;
	int len;

};


#endif