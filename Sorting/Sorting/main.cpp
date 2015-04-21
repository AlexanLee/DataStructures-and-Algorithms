#include <iostream>
#include <cassert>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "BucketSort.h"
using namespace std;

int main()
{
	int arr[] = {3, -5, 5, 2, 0, -10, 80, 35, 1, 5, -9, 100, 4, 0, -2, 6, -10, 7};
	//int arr[] = { 3, -5, 5, 2};
	//int arr[] = {12, 40, 30, 8, 10, 70, 60, 90, -5, -10};
	int len = sizeof(arr) / sizeof(int);

	// Test Selection Sort
	cout << endl << "Test Selection Sort" << endl;
	SelectionSort testSS(arr, len);
	testSS.show();
	testSS.sort();
	assert(testSS.isSorted());
	testSS.show();

	// Test Bubble Sort
	cout << endl << "Test Bubble Sort" << endl;
	BubbleSort testBS(arr, len);
	testBS.show();
	testBS.sort();
	assert(testBS.isSorted());
	testBS.show();

	// Test InsertionSort Sort
	cout << endl << "Test InsertionSort Sort" << endl;
	InsertionSort testIS(arr, len);
	testIS.show();
	testIS.sort();
	assert(testIS.isSorted());
	testIS.show();

	// Test ShellSort Sort
	cout << endl << "Test ShellSort Sort" << endl;
	ShellSort testShellS(arr, len);
	testShellS.show();
	testShellS.sort();
	assert(testShellS.isSorted());
	testShellS.show();

	// Test Merge Sort
	cout << endl << "Test Merge Sort" << endl;
	MergeSort testMS(arr, len);
	testMS.show();
	testMS.sort();
	assert(testMS.isSorted());
	testMS.show();

	// Test Quick Sort
	cout << endl << "Test Quick Sort" << endl;
	QuickSort testQS(arr, len);
	testQS.show();
	testQS.sort();
	assert(testQS.isSorted());
	testQS.show();

	// Test HeapSort Sort
	cout << endl << "Test HeapSort Sort" << endl;
	HeapSort testHS(arr, len);
	testHS.show();
	testHS.sort();
	assert(testHS.isSorted());
	testHS.show();

	// Test Counting Sort
	// Inputs should be between 0~MAX
	int arr1[] = { 7, 8, 5, 1, 2, 6, 9, 3, 4, 0, 5, 6, 8 };
	int len1 = sizeof(arr1) / sizeof(int);
	cout << endl << "Test Counting Sort" << endl;
	CountingSort testCS(arr1, len1);
	testCS.show();
	testCS.sort();
	assert(testCS.isSorted());
	testCS.show();

	// Test Radix Sort
	int arr2[] = { 329, 457, 657, 839, 436, 720, 355 };
	int len2 = sizeof(arr2) / sizeof(int);
	cout << endl << "Test Radix Sort" << endl;
	RadixSort testRS(arr2, len2);
	testRS.show();
	testRS.sort();
	assert(testRS.isSorted());
	testRS.show();

	// Test Bucket Sort
	float arr3[] = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 };
	int len3 = sizeof(arr3) / sizeof(float);
	cout << endl << "Test Bucket Sort" << endl;
	BucketSort testBucketS(arr3, len3);
	testBucketS.show();
	testBucketS.sort();
	assert(testBucketS.isSorted());
	testBucketS.show();

	return 0;
}