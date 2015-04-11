#include <iostream>
#include <cassert>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
using namespace std;

int main()
{
	int arr[] = {3, -5, 5, 2, 0, -10, 1, 5, 9, 100, 4, 0, -2, 6, -10, 7, 8};
	//int arr[] = { 3, -5, 5, 2 };
	int len = sizeof(arr) / sizeof(int);

	// Test Selection Sorting
	cout << endl << "Test Selection Sorting" << endl;
	SelectionSort testSS(arr, len);
	testSS.show();
	testSS.sort();
	assert(testSS.isSorted());
	testSS.show();

	// Test Bubble Sorting
	cout << endl << "Test Bubble Sorting" << endl;
	BubbleSort testBS(arr, len);
	testBS.show();
	testBS.sort();
	assert(testBS.isSorted());
	testBS.show();

	// Test InsertionSort Sorting
	cout << endl << "Test InsertionSort Sorting" << endl;
	InsertionSort testIS(arr, len);
	testIS.show();
	testIS.sort();
	assert(testIS.isSorted());
	testIS.show();

	// Test ShellSort Sorting
	cout << endl << "Test ShellSort Sorting" << endl;
	ShellSort testShellS(arr, len);
	testShellS.show();
	testShellS.sort();
	assert(testShellS.isSorted());
	testShellS.show();

	// Test Merge Sorting
	cout << endl << "Test Merge Sorting" << endl;
	MergeSort testMS(arr, len);
	testMS.show();
	testMS.sort();
	assert(testMS.isSorted());
	testMS.show();

	return 0;
}