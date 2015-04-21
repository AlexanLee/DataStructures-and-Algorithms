#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Searching/HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableUT_Namespace
{
	TEST_CLASS(HashTableUT)
	{
	public:
		HashTableUT()
		{
			testHT = new HashTable;
		}

		~HashTableUT()
		{
			delete testHT;
		}

		TEST_METHOD(HashTable_Normal_Test)
		{
			int key[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
			int val[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
			int len = sizeof(key) / sizeof(int);

			testHT->initST(key, val, len);

			bool expect, actual;
			expect = true;
			actual = testHT->erase(14);
			Assert::AreEqual(expect, actual);

			expect = true;
			actual = testHT->erase(4);
			Assert::AreEqual(expect, actual);

			expect = false;
			actual = testHT->erase(100);
			Assert::AreEqual(expect, actual);

			Value expectVal, actualVal;
			expectVal = 5;
			actualVal = testHT->search(5);
			Assert::AreEqual(expectVal, actualVal);

			expectVal = NULL;
			actualVal = testHT->search(4);
			Assert::AreEqual(expectVal, actualVal);
		}

	public:
		HashTable * testHT;

	};
}