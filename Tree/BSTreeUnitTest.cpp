#define BOOST_TEST_MODULE Tree_Test_Module

#include "stdafx.h"
#include "../Tree/BSTree.hpp"

struct BSTree_Fixture
{
public:
	BSTree_Fixture()
	{
		testBSTree = new BSTree<int>();
	}
	~BSTree_Fixture()
	{
		delete testBSTree;
	}

	BSTree<int> * testBSTree;
};

BOOST_FIXTURE_TEST_SUITE(BSTree_Test_Suite, BSTree_Fixture)

BOOST_AUTO_TEST_CASE(BSTree_Normal_Test)
{
	// isEmpty & getHight-----------------------------
	BOOST_REQUIRE(testBSTree->isEmpty() == true);
	BOOST_REQUIRE(testBSTree->getHeight() == 0);

	// addNode & searchNode ---------------------------
	BOOST_REQUIRE(testBSTree->addNode(1, 1) == true);
	BOOST_REQUIRE(testBSTree->searchNode(1) != NULL);
	BOOST_REQUIRE((testBSTree->searchNode(1))->data == 1);
	BOOST_REQUIRE(testBSTree->isEmpty() == false);
	BOOST_REQUIRE(testBSTree->getHeight() == 1);

	BOOST_REQUIRE(testBSTree->addNode(0, 0) == true);
	BOOST_REQUIRE(testBSTree->searchNode(0) != NULL);
	BOOST_REQUIRE((testBSTree->searchNode(0))->data == 0);
	BOOST_REQUIRE(testBSTree->getHeight() == 2);

	BOOST_REQUIRE(testBSTree->addNode(2, 2) == true);
	BOOST_REQUIRE(testBSTree->searchNode(2) != NULL);
	BOOST_REQUIRE((testBSTree->searchNode(2))->data == 2);
	BOOST_REQUIRE(testBSTree->getHeight() == 2);

	BOOST_REQUIRE(testBSTree->addNode(3, 3) == true);
	BOOST_REQUIRE(testBSTree->searchNode(3) != NULL);
	BOOST_REQUIRE((testBSTree->searchNode(3))->data == 3);
	BOOST_REQUIRE(testBSTree->getHeight() == 3);

	// getMinimum & getMaxmum ----------------------
	BOOST_REQUIRE(testBSTree->getMinimum() == 0);
	BOOST_REQUIRE(testBSTree->getMaxmum() == 3);

	// preOrder ------------------------------------
	testBSTree->preOrder();
	BOOST_REQUIRE(getTestData(*testBSTree, 0) == 1);
	BOOST_REQUIRE(getTestData(*testBSTree, 1) == 0);
	BOOST_REQUIRE(getTestData(*testBSTree, 2) == 2);
	BOOST_REQUIRE(getTestData(*testBSTree, 3) == 3);

	// inOrder -------------------------------------
	testBSTree->inOrder();
	BOOST_REQUIRE(getTestData(*testBSTree, 0) == 0);
	BOOST_REQUIRE(getTestData(*testBSTree, 1) == 1);
	BOOST_REQUIRE(getTestData(*testBSTree, 2) == 2);
	BOOST_REQUIRE(getTestData(*testBSTree, 3) == 3);

	// postOrder -----------------------------------
	testBSTree->postOrder();
	BOOST_REQUIRE(getTestData(*testBSTree, 0) == 0);
	BOOST_REQUIRE(getTestData(*testBSTree, 1) == 3);
	BOOST_REQUIRE(getTestData(*testBSTree, 2) == 2);
	BOOST_REQUIRE(getTestData(*testBSTree, 3) == 1);

	// destroy -------------------------------------
	testBSTree->destroy();

	// creatBSTree --------------------------------
	int key[] = { 7, 3, 1, 2, 5, 4, 6, 9, 8, 10, 11 };
	int value[] = { 7, 3, 1, 2, 5, 4, 6, 9, 8, 10, 11 };
	unsigned len = sizeof(key) / sizeof(int);
	testBSTree->creatTree(key, value, len);

	// getPredecessor ------------------------------
	BOOST_REQUIRE(testBSTree->getPredecessor(7) == NULL);
	BOOST_REQUIRE((testBSTree->getPredecessor(2))->data == 1);
	BOOST_REQUIRE((testBSTree->getPredecessor(5))->data == 4);

	// getSuccessor --------------------------------
	BOOST_REQUIRE(testBSTree->getSuccessor(7)->data == 8);
	BOOST_REQUIRE(testBSTree->getSuccessor(6)->data == 7);
	BOOST_REQUIRE(testBSTree->getSuccessor(9)->data == 10);
	BOOST_REQUIRE(testBSTree->getSuccessor(11) == NULL);

}

BOOST_AUTO_TEST_CASE(BSTree_delNode_Test)
{
	// creatBSTree --------------------------------
	int key[] = { 7, 3, 1, 0, 5, 4, 6, 9, 8, 10, 11 };
	int value[] = { 7, 3, 1, 0, 5, 4, 6, 9, 8, 10, 11 };
	unsigned len = sizeof(key) / sizeof(int);
	testBSTree->creatTree(key, value, len);

	// delNode ----------------------------------
	// delete root with two children
	Node<int> * treeRoot = testBSTree->searchNode(7);
	BOOST_REQUIRE((treeRoot->left)->data == 3);
	BOOST_REQUIRE((treeRoot->right)->data == 9);
	BOOST_REQUIRE(testBSTree->delNode(7) == true);

	BOOST_REQUIRE(testBSTree->searchNode(7) == NULL);
	treeRoot = testBSTree->searchNode(8);
	BOOST_REQUIRE((treeRoot->left)->data == 3);
	BOOST_REQUIRE((treeRoot->right)->data == 9);
	 
	// delete node (not root) with two children
	Node<int> * treeNode = testBSTree->searchNode(3);
	BOOST_REQUIRE((treeNode->left)->data == 1);
	BOOST_REQUIRE((treeNode->right)->data == 5);
	BOOST_REQUIRE(testBSTree->delNode(3) == true);

	treeNode = testBSTree->searchNode(4);
	BOOST_REQUIRE((treeNode->left)->data == 1);
	BOOST_REQUIRE((treeNode->right)->data == 5);

	// delete node with only one left child
	treeNode = testBSTree->searchNode(1);
	BOOST_REQUIRE((treeNode->left)->data == 0);
	BOOST_REQUIRE(treeNode->right == NULL);
	BOOST_REQUIRE(testBSTree->delNode(1) == true);

	BOOST_REQUIRE(testBSTree->searchNode(1) == NULL);
	treeNode = testBSTree->searchNode(4);
	BOOST_REQUIRE((treeNode->left)->data == 0);
	BOOST_REQUIRE((treeNode->right)->data == 5);

	// delete node with two children (right->right, without any left child)
	treeNode = testBSTree->searchNode(9);
	BOOST_REQUIRE((treeNode->parent)->data == 8);
	BOOST_REQUIRE(treeNode->left == NULL);
	BOOST_REQUIRE((treeNode->right)->data == 10);
	BOOST_REQUIRE(testBSTree->delNode(9) == true);

	treeNode = testBSTree->searchNode(10);
	BOOST_REQUIRE((treeNode->parent)->data == 8);
	BOOST_REQUIRE(treeNode->left == NULL);
	BOOST_REQUIRE((treeNode->right)->data == 11);

	// delete node with only one right child
	BOOST_REQUIRE(testBSTree->delNode(10) == true);

	treeNode = testBSTree->searchNode(11);
	BOOST_REQUIRE((treeNode->parent)->data == 8);
	BOOST_REQUIRE(treeNode->left == NULL);
	BOOST_REQUIRE(treeNode->right == NULL);

	BOOST_REQUIRE(testBSTree->delNode(11) == true);

	// delete root with only left tree
	treeNode = testBSTree->searchNode(4);
	BOOST_REQUIRE((treeNode->parent)->data == 8);
	BOOST_REQUIRE(testBSTree->delNode(8) == true);

	treeNode = testBSTree->searchNode(4);
	BOOST_REQUIRE(treeNode->parent == NULL);

	// delete other noods
	BOOST_REQUIRE(testBSTree->delNode(0) == true);
	BOOST_REQUIRE(testBSTree->delNode(5) == true);
	BOOST_REQUIRE(testBSTree->delNode(6) == true);

	// delete root with left or right child
	treeNode = testBSTree->searchNode(4);
	BOOST_REQUIRE(treeNode->left == NULL);
	BOOST_REQUIRE(treeNode->right == NULL);
	BOOST_REQUIRE(testBSTree->delNode(4) == true);

	BOOST_REQUIRE(testBSTree->searchNode(4) == NULL);

}

//BOOST_AUTO_TEST_CASE(BSTree_CopyConstructor_Test)
//{
//	// leave blank
//}
//
//BOOST_AUTO_TEST_CASE(BSTree_EqualOperator_Test)
//{
//	// leave blank
//}

BOOST_AUTO_TEST_SUITE_END()
