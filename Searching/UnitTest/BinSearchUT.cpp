#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Searching/BinSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinSearchUT_Namespace
{		
	TEST_CLASS(BinSearchUT)
	{
	public:
		BinSearchUT()
		{
			testBS = new BinSearch;
		}

		~BinSearchUT()
		{
			delete testBS;
		}
		
		TEST_METHOD(BinSearch_Normal_Test)
		{
			int key[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
			int val[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
			int len = sizeof(key) / sizeof(int);

			bool actual = testBS->isEmpty();
			bool expect = true;
			Assert::AreEqual(expect, actual);

			testBS->initST(key, val, len);
			actual = testBS->isEmpty();
			expect = false;
			Assert::AreEqual(expect, actual);

			int sz = testBS->size();
			Assert::AreEqual(len, sz);
		}

	public:
		BinSearch * testBS;

	};
}