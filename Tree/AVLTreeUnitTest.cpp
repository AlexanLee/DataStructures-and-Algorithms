      
#include "stdafx.h"
#include "../Tree/AVLTree.hpp"

struct AVLTree_Fixture
{
public:
	AVLTree_Fixture()
	{
		testAVLTree = new AVLTree<int>();
	}
	~AVLTree_Fixture()
	{
		delete testAVLTree;
	}

	AVLTree<int> * testAVLTree;

};

BOOST_FIXTURE_TEST_SUITE(AVLTree_Test_Suite, AVLTree_Fixture)

BOOST_AUTO_TEST_CASE( AVLTree_addNode_Test )  
{
	// add node next next to root and cause "left left/right" imbalance
	// left left
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(4, 4) == true);
	BOOST_REQUIRE(testAVLTree->addNode(3, 3) == true);
	testAVLTree->destroy();
	// left right
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(3, 3) == true);
	BOOST_REQUIRE(testAVLTree->addNode(4, 4) == true);
	testAVLTree->destroy();
	// add node next next to root and cause "right left/right" imbalance
	// right left
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(6, 6) == true);
	testAVLTree->destroy();
	// right right
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(8, 8) == true);
	testAVLTree->destroy();

	// add node not next next to root and cause "left left/right" imbalance
	// left left
	BOOST_REQUIRE(testAVLTree->addNode(6, 6) == true);
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(3, 3) == true);
	BOOST_REQUIRE(testAVLTree->addNode(2, 2) == true);
	testAVLTree->destroy();

	// left right
	BOOST_REQUIRE(testAVLTree->addNode(6, 6) == true);
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(3, 3) == true);
	BOOST_REQUIRE(testAVLTree->addNode(4, 4) == true);
	testAVLTree->destroy();

	// add node next next to root and cause "right left/right" imbalance
	// right left
	BOOST_REQUIRE(testAVLTree->addNode(6, 6) == true);
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(10, 10) == true);
	BOOST_REQUIRE(testAVLTree->addNode(8, 8) == true);
	testAVLTree->destroy();

	// right right
	BOOST_REQUIRE(testAVLTree->addNode(6, 6) == true);
	BOOST_REQUIRE(testAVLTree->addNode(5, 5) == true);
	BOOST_REQUIRE(testAVLTree->addNode(7, 7) == true);
	BOOST_REQUIRE(testAVLTree->addNode(10, 10) == true);
	BOOST_REQUIRE(testAVLTree->addNode(11, 11) == true);
	testAVLTree->destroy();

}

BOOST_AUTO_TEST_CASE(AVLTree_delNode_Test)
{
	// delete root and cause "right right" imbalance --------------------------------
	// actually, only "right right" imbalance will be caused at such condition ------
	int key1[] = { 5, 4, 6, 2 };
	int value1[] = { 5, 4, 6, 2 };
	unsigned len1 = sizeof(key1) / sizeof(int);
	testAVLTree->creatTree(key1, value1, len1);
	BOOST_REQUIRE(testAVLTree->delNode(5) == true);
	testAVLTree->destroy();

	// delete right node of 'root' and cause "left left/right" imbalance ----------------
	// left left
	int key31[] = { 6, 4, 7, 3, 5, 8, 2 };
	int value31[] = { 6, 4, 7, 3, 5, 8, 2 };
	unsigned len31 = sizeof(key31) / sizeof(int);
	testAVLTree->creatTree(key31, value31, len31);
	BOOST_REQUIRE(testAVLTree->delNode(7) == true);
	testAVLTree->destroy();

	// left right
	int key32[] = { 6, 3, 7, 2, 4, 8, 5 };
	int value32[] = { 6, 3, 7, 2, 4, 8, 5 };
	unsigned len32 = sizeof(key32) / sizeof(int);
	testAVLTree->creatTree(key32, value32, len32);
	BOOST_REQUIRE(testAVLTree->delNode(7) == true);
	testAVLTree->destroy();

	// delete left node of 'root' and cause "right left/right" imbalance -------------------
	// right left
	int key21[] = { 4, 3, 7, 2, 6, 9, 5 };
	int value21[] = { 4, 3, 7, 2, 6, 9, 5 };
	unsigned len21 = sizeof(key21) / sizeof(int);
	testAVLTree->creatTree(key21, value21, len21);
	BOOST_REQUIRE(testAVLTree->delNode(3) == true);
	testAVLTree->destroy();
	// right right
	int key22[] = { 5, 4, 7, 2, 6, 9, 10 };
	int value22[] = { 5, 4, 7, 2, 6, 9, 10 };
	unsigned len22 = sizeof(key22) / sizeof(int);
	testAVLTree->creatTree(key22, value22, len22);
	BOOST_REQUIRE(testAVLTree->delNode(4) == true);
	testAVLTree->destroy();

	// delete node and cause "left left/right" imbalance -------------------
	// left left -- imbalanced node is at root
	int key41[] = { 8, 5, 9, 4, 6, 10, 3 };
	int value41[] = { 8, 5, 9, 4, 6, 10, 3 };
	unsigned len41 = sizeof(key41) / sizeof(int);
	testAVLTree->creatTree(key41, value41, len41);
	BOOST_REQUIRE(testAVLTree->delNode(10) == true);
	testAVLTree->destroy();

	// left right -- imbalanced node is at root
	int key42[] = { 8, 5, 9, 4, 6, 10, 7 };
	int value42[] = { 8, 5, 9, 4, 6, 10, 7 };
	unsigned len42 = sizeof(key42) / sizeof(int);
	testAVLTree->creatTree(key42, value42, len42);
	BOOST_REQUIRE(testAVLTree->delNode(10) == true);
	testAVLTree->destroy();

	// left left -- imbalanced node is not at root
	int key43[] = { 5, 8, 3, 7, 9, 2, 4, 1 };
	int value43[] = { 5, 8, 3, 7, 9, 2, 4, 1 };
	unsigned len43 = sizeof(key43) / sizeof(int);
	testAVLTree->creatTree(key43, value43, len43);
	BOOST_REQUIRE(testAVLTree->delNode(4) == true);
	testAVLTree->destroy();

	// left right -- imbalanced node is not at root
	int key44[] = { 5, 8, 3, 7, 9, 1, 4, 2 };
	int value44[] = { 5, 8, 3, 7, 9, 1, 4, 2 };
	unsigned len44 = sizeof(key44) / sizeof(int);
	testAVLTree->creatTree(key44, value44, len44);
	BOOST_REQUIRE(testAVLTree->delNode(4) == true);
	testAVLTree->destroy();

	// delete node and cause "right left/right" imbalance -------------------
	// right left -- imbalanced node is at root
	int key51[] = { 8, 5, 11, 4, 10, 12, 9 };
	int value51[] = { 8, 5, 11, 4, 10, 12, 9 };
	unsigned len51 = sizeof(key51) / sizeof(int);
	testAVLTree->creatTree(key51, value51, len51);
	BOOST_REQUIRE(testAVLTree->delNode(4) == true);
	testAVLTree->destroy();

	// right right -- imbalanced node is at root
	int key52[] = { 8, 5, 11, 4, 10, 12, 13 };
	int value52[] = { 8, 5, 11, 4, 10, 12, 13 };
	unsigned len52 = sizeof(key52) / sizeof(int);
	testAVLTree->creatTree(key52, value52, len52);
	BOOST_REQUIRE(testAVLTree->delNode(4) == true);
	testAVLTree->destroy();

	// right left -- imbalanced node is not at root
	int key53[] = { 5, 8, 3, 7, 10, 1, 4, 2, 9 };
	int value53[] = { 5, 8, 3, 7, 10, 1, 4, 2, 9 };
	unsigned len53 = sizeof(key53) / sizeof(int);
	testAVLTree->creatTree(key53, value53, len53);
	BOOST_REQUIRE(testAVLTree->delNode(7) == true);
	testAVLTree->destroy();

	// right right -- imbalanced node is not at root
	int key54[] = { 5, 8, 3, 7, 9, 1, 4, 2, 10 };
	int value54[] = { 5, 8, 3, 7, 9, 1, 4, 2, 10 };
	unsigned len54 = sizeof(key54) / sizeof(int);
	testAVLTree->creatTree(key54, value54, len54);
	BOOST_REQUIRE(testAVLTree->delNode(7) == true);
	testAVLTree->destroy();

}

//BOOST_AUTO_TEST_CASE(AVLTree_CopyConstructor_Test)
//{
//	// leave blank
//}
//
//BOOST_AUTO_TEST_CASE(AVLTree_EqualOperator_Test)
//{
//	// leave blank
//}

BOOST_AUTO_TEST_SUITE_END()