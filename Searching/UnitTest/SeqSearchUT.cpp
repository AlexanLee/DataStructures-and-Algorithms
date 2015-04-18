#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Searching/SeqSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SeqSearchUT_Namespace
{
	TEST_CLASS(SeqSearchUT)
	{
	public:
		SeqSearchUT()
		{
			testSS = new SeqSearch;
		}

		~SeqSearchUT()
		{
			delete testSS;
		}

		TEST_METHOD(SeqSearch_Normal_Test)
		{
			int key[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
			int val[] = { 5, 7, 9, -7, 10, -1, 3, 8, 12, -4, 15, 1, -2 };
			int len = sizeof(key) / sizeof(int);

			bool actual = testSS->isEmpty();
			bool expect = true;
			Assert::AreEqual(expect, actual);

			testSS->initST(key, val, len);
			actual = testSS->isEmpty();
			expect = false;
			Assert::AreEqual(expect, actual);

			int sz = testSS->size();
			Assert::AreEqual(len, sz);
		}

	public:
		SeqSearch * testSS;

	};
}