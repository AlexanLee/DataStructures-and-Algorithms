#include <iostream>
#include <cassert>
#include "SeqSearch.h"
#include "BinSearch.h"
using namespace std;

int main()
{
	int key[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
	int val[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
	int len = sizeof(key) / sizeof(int);
	
	// Test Sequential Search ------------------------------------
	SeqSearch seqSearch;

	assert(seqSearch.isEmpty());
	assert(seqSearch.size() == 0);

	seqSearch.initST(key, val, len);
	SeqSearch seqSearch2(seqSearch);
	SeqSearch seqSearch3 = seqSearch;

	assert(!seqSearch.isEmpty());
	assert(seqSearch.size() == len);

	assert(seqSearch.erase(5));
	assert(seqSearch.erase(8));
	assert(seqSearch.erase(7));
	assert(!seqSearch.erase(0));
	assert(seqSearch.size() == len - 3);

	assert(seqSearch.search(-1) == -1);
	assert(seqSearch.search(15) == 15);
	assert(seqSearch.search(0) == NULL);

	seqSearch.destroy();
	assert(seqSearch.isEmpty());

	// Test Binary Search ------------------------------------
	BinSearch binSearch;

	assert(binSearch.isEmpty());
	assert(binSearch.size() == 0);

	binSearch.initST(key, val, len);
	BinSearch binSearch2(binSearch);
	BinSearch binSearch3 = binSearch;

	assert(!binSearch.isEmpty());
	assert(binSearch.size() == len);

	assert(binSearch.erase(5));
	assert(binSearch.erase(8));
	assert(binSearch.erase(7));
	assert(!binSearch.erase(0));
	assert(binSearch.size() == len - 3);

	assert(binSearch.search(-1) == -1);
	assert(binSearch.search(15) == 15);
	assert(binSearch.search(0) == NULL);

	return 0;
}