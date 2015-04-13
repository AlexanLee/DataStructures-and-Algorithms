#include <iostream>
#include <cassert>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
using namespace std;

int main()
{
	int arr[] = {3, -5, 5, 2, 0, -10, 80, 35, 1, 5, -9, 100, 4, 0, -2, 6, -10, 7, 8};
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

	return 0;
}