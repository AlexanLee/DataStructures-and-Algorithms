#define BOOST_TEST_MODULE LinkedList_Test_Module

#include "stdafx.h"
#include "..\DoubleLinkedList\linkedlist.h"

struct LinkedList_Fixture
{
public:
	LinkedList_Fixture()
	{
		testLinkedList = new LinkedList();
	}
	~LinkedList_Fixture()
	{
		delete testLinkedList;
	}

	LinkedList * testLinkedList;
};

BOOST_FIXTURE_TEST_SUITE(LinkedList_Test_Suite, LinkedList_Fixture)

BOOST_AUTO_TEST_CASE(LinkedList_Normal_Test)
{
	// isEmpty --------------------------------------------
	BOOST_REQUIRE(testLinkedList->isEmpty() == true);

	// getLenOfList ---------------------------------------
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 0);

	// addNode & getNode  ---------------------------------
	BOOST_REQUIRE(testLinkedList->addNode(0, 1) == true);
	BOOST_REQUIRE((testLinkedList->getNode(0))->data == 1);
	BOOST_REQUIRE((testLinkedList->getNode(0))->pre != NULL);
	BOOST_REQUIRE((testLinkedList->getNode(0))->next != NULL);
	BOOST_REQUIRE(testLinkedList->isEmpty() == false);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 1);

	BOOST_REQUIRE(testLinkedList->addNode(1, 3) == true);
	BOOST_REQUIRE((testLinkedList->getNode(1))->data == 3);
	BOOST_REQUIRE((testLinkedList->getNode(1))->pre != NULL);
	BOOST_REQUIRE((testLinkedList->getNode(1))->next != NULL);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 2);

	BOOST_REQUIRE(testLinkedList->addNode(1, 2) == true);
	BOOST_REQUIRE((testLinkedList->getNode(1))->data == 2);
	BOOST_REQUIRE((testLinkedList->getNode(1))->pre != NULL);
	BOOST_REQUIRE((testLinkedList->getNode(1))->next != NULL);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 3);

	// deleteNode -----------------------------------------
	BOOST_REQUIRE(testLinkedList->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList->getNode(1))->data == 3);
	BOOST_REQUIRE((testLinkedList->getNode(1))->pre != NULL);
	BOOST_REQUIRE((testLinkedList->getNode(1))->next != NULL);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 2);

	BOOST_REQUIRE(testLinkedList->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList->getNode(0))->data == 1);
	BOOST_REQUIRE((testLinkedList->getNode(0))->pre != NULL);
	BOOST_REQUIRE((testLinkedList->getNode(0))->next != NULL);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 1);

	BOOST_REQUIRE(testLinkedList->deleteNode(0) == true);
	BOOST_REQUIRE(testLinkedList->getLenOfList() == 0);

}

BOOST_AUTO_TEST_CASE(LinkedList_Abnormal_Test)
{
	// initialize ------------------------------------------
	BOOST_REQUIRE(testLinkedList->addNode(0, 1) == true);
	BOOST_REQUIRE(testLinkedList->addNode(1, 2) == true);
	BOOST_REQUIRE(testLinkedList->addNode(2, 3) == true);

	// addNode -------------------------------------------
	BOOST_REQUIRE_THROW(testLinkedList->addNode(-1, 100), out_of_range);
	BOOST_REQUIRE_THROW(testLinkedList->addNode(10, 100), out_of_range);

	// deleteNode ----------------------------------------
	BOOST_REQUIRE_THROW(testLinkedList->deleteNode(-1), out_of_range);
	BOOST_REQUIRE_THROW(testLinkedList->deleteNode(10), out_of_range);

	// getNode --------------------------------------------
	BOOST_REQUIRE_THROW(testLinkedList->getNode(-1), out_of_range);
	BOOST_REQUIRE_THROW(testLinkedList->getNode(10), out_of_range);
}

BOOST_AUTO_TEST_CASE(LinkedList_CopyConstructor_Test)
{
	// initialize ------------------------------------------
	BOOST_REQUIRE(testLinkedList->addNode(0, 1) == true);
	BOOST_REQUIRE(testLinkedList->addNode(1, 2) == true);
	BOOST_REQUIRE(testLinkedList->addNode(2, 3) == true);

	// check copy constructor ------------------------------
	LinkedList * testLinkedList2 = new LinkedList(*testLinkedList);
	BOOST_REQUIRE(testLinkedList2->isEmpty() == false);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 3);
	BOOST_REQUIRE((testLinkedList2->getNode(0))->data == 1);
	BOOST_REQUIRE((testLinkedList2->getNode(1))->data == 2);
	BOOST_REQUIRE((testLinkedList2->getNode(2))->data == 3);

	BOOST_REQUIRE(testLinkedList2->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList2->getNode(1))->data == 3);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 2);

	BOOST_REQUIRE(testLinkedList2->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList2->getNode(0))->data == 1);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 1);

	BOOST_REQUIRE(testLinkedList2->deleteNode(0) == true);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 0);
}

BOOST_AUTO_TEST_CASE(LinkedList_EqualOperator_Test)
{
	// initialize ------------------------------------------
	BOOST_REQUIRE(testLinkedList->addNode(0, 1) == true);
	BOOST_REQUIRE(testLinkedList->addNode(1, 2) == true);
	BOOST_REQUIRE(testLinkedList->addNode(2, 3) == true);

	// check copy constructor ------------------------------
	LinkedList * testLinkedList2 = new LinkedList();
	*testLinkedList2 = *testLinkedList;
	BOOST_REQUIRE(testLinkedList2->isEmpty() == false);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 3);
	BOOST_REQUIRE((testLinkedList2->getNode(0))->data == 1);
	BOOST_REQUIRE((testLinkedList2->getNode(1))->data == 2);
	BOOST_REQUIRE((testLinkedList2->getNode(2))->data == 3);

	BOOST_REQUIRE(testLinkedList2->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList2->getNode(1))->data == 3);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 2);

	BOOST_REQUIRE(testLinkedList2->deleteNode(1) == true);
	BOOST_REQUIRE((testLinkedList2->getNode(0))->data == 1);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 1);

	BOOST_REQUIRE(testLinkedList2->deleteNode(0) == true);
	BOOST_REQUIRE(testLinkedList2->getLenOfList() == 0);
}

BOOST_AUTO_TEST_SUITE_END()