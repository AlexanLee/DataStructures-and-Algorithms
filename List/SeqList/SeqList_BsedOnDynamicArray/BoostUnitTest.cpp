// BoostUnitTest.cpp
#define  BOOST_TEST_MODULE ArrayList_Test_Module

#include "stdafx.h"
#include "..\SeqList\seqlist.h"

struct ArrayList_Fixture
{
	ArrayList_Fixture()
	{
		BOOST_TEST_MESSAGE("Setup fixture");
		testArrayList = new SeqList(1024);
	}
	~ArrayList_Fixture()
	{
		BOOST_TEST_MESSAGE("Teardown fixture");
		delete testArrayList;
	}

	SeqList * testArrayList;
};

// BOOST_AUTO_TEST_SUITE(ArrayList_Test_Suite)
BOOST_FIXTURE_TEST_SUITE(ArrayList_Test_Suite, ArrayList_Fixture)

BOOST_AUTO_TEST_CASE(ArrayList_Abnormal_Test)
{
	// Set values to the array list
	int testArray[] = { 1, 2, 3, 4, 5 };	// 5 个元素
	int testLenOfList = sizeof(testArray) / sizeof(int);
	testArrayList->setSeqList(testArray, testLenOfList);
	// BOOST_REQUIRE_THROW(testArrayList->setArrayList(testArray, testLenOfList), out_of_range);


	// Method getItem-----------------------------------------------
	// If the position of the item you want to get is less than zero
	BOOST_REQUIRE_THROW(testArrayList->getItem(-1), out_of_range);
	// If the position of the item you want to get is larger than the length of the list
	BOOST_REQUIRE_THROW(testArrayList->getItem(10), out_of_range);


	// Method insert-------------------------------------------------
	// If the inserting position is less than zero
	BOOST_REQUIRE_THROW(testArrayList->insert(-1, 10), out_of_range);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList);

	// If the inserting position is larger than the length of the list
	BOOST_REQUIRE_THROW(testArrayList->insert(10, 10), out_of_range);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList);


	// Method erase-------------------------------------------------
	// If the erasing position is less than zero
	BOOST_REQUIRE_THROW(testArrayList->erase(-1), out_of_range);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList);

	// If the erasing position is larger than the length of the list
	BOOST_REQUIRE_THROW(testArrayList->erase(10), out_of_range);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList);

}

BOOST_AUTO_TEST_CASE(ArrayList_Normal_Test)
{
	bool expected;
	bool actual;
	// Method empty-------------------------------------------------
	expected = true;
	actual = testArrayList->empty();
	BOOST_REQUIRE(expected == actual);

	// Set values to the array list
	int testArray[] = { 1, 2, 3, 4, 5 };	// 5 个元素
	int testLenOfList = sizeof(testArray) / sizeof(int);
	testArrayList->setSeqList(testArray, testLenOfList);
	// BOOST_REQUIRE_THROW(testArrayList->setArrayList(testArray, testLenOfList), out_of_range);

	// Method getItem-----------------------------------------------
	BOOST_REQUIRE(testArrayList->getItem(1) == testArray[1]);


	// Method empty-------------------------------------------------
	expected = false;
	actual = testArrayList->empty();
	BOOST_REQUIRE(expected == actual);


	// Method insert-------------------------------------------------
	expected = true;
	actual = testArrayList->insert(1, 10);
	BOOST_REQUIRE(expected == actual);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList + 1);
	BOOST_REQUIRE(testArrayList->getItem(1) == 10);


	// Method erase-------------------------------------------------
	expected = true;
	actual = testArrayList->erase(1);
	BOOST_REQUIRE(expected, actual);
	BOOST_REQUIRE(testArrayList->getLenOfList() == testLenOfList);
	BOOST_REQUIRE(testArrayList->getItem(1) == testArray[1]);

}

BOOST_AUTO_TEST_CASE(ArrayList_CopyConstructor_Test)
{
	bool expected;
	bool actual;
	// Set values to the array list
	int testArray[] = { 1, 2, 3, 4, 5 };	// 5 个元素
	int testLenOfList = sizeof(testArray) / sizeof(int);
	testArrayList->setSeqList(testArray, testLenOfList);
	// BOOST_REQUIRE_THROW(testArrayList->setArrayList(testArray, testLenOfList), out_of_range);

	// Copy constructor
	//SeqList * copySeqList(testArrayList);		// 极容易写成这样子。错误。
												// 需要给copySeqList分配内存
	SeqList * copySeqList = new SeqList(*testArrayList);

	// Method getItem-----------------------------------------------
	BOOST_REQUIRE(copySeqList->getItem(1) == testArray[1]);


	// Method empty-------------------------------------------------
	expected = false;
	actual = copySeqList->empty();
	BOOST_REQUIRE(expected == actual);


	// Method insert-------------------------------------------------
	expected = true;
	actual = copySeqList->insert(1, 10);
	BOOST_REQUIRE(expected == actual);
	BOOST_REQUIRE(copySeqList->getLenOfList() == testLenOfList + 1);
	BOOST_REQUIRE(copySeqList->getItem(1) == 10);


	// Method erase-------------------------------------------------
	expected = true;
	actual = copySeqList->erase(1);
	BOOST_REQUIRE(expected, actual);
	BOOST_REQUIRE(copySeqList->getLenOfList() == testLenOfList);
	BOOST_REQUIRE(copySeqList->getItem(1) == testArray[1]);
}

BOOST_AUTO_TEST_CASE(ArrayList_EqualOperator_Test)
{
	bool expected;
	bool actual;
	// Set values to the array list
	int testArray[] = { 1, 2, 3, 4, 5 };	// 5 个元素
	int testLenOfList = sizeof(testArray) / sizeof(int);
	testArrayList->setSeqList(testArray, testLenOfList);
	// BOOST_REQUIRE_THROW(testArrayList->setArrayList(testArray, testLenOfList), out_of_range);

	// Copy constructor
	SeqList * copySeqList = new SeqList(2048);
	// copySeqList = testArrayList;		// 极易犯的一个低级错误
	*copySeqList = *testArrayList;

	// Method getItem-----------------------------------------------
	BOOST_REQUIRE(copySeqList->getItem(1) == testArray[1]);


	// Method empty-------------------------------------------------
	expected = false;
	actual = copySeqList->empty();
	BOOST_REQUIRE(expected == actual);


	// Method insert-------------------------------------------------
	expected = true;
	actual = copySeqList->insert(1, 10);
	BOOST_REQUIRE(expected == actual);
	BOOST_REQUIRE(copySeqList->getLenOfList() == testLenOfList + 1);
	BOOST_REQUIRE(copySeqList->getItem(1) == 10);


	// Method erase-------------------------------------------------
	expected = true;
	actual = copySeqList->erase(1);
	BOOST_REQUIRE(expected, actual);
	BOOST_REQUIRE(copySeqList->getLenOfList() == testLenOfList);
	BOOST_REQUIRE(copySeqList->getItem(1) == testArray[1]);
}

BOOST_AUTO_TEST_SUITE_END();