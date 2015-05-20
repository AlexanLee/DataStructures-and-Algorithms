#include "stdafx.h"
#include "../Graph/Hungarian.h"

struct Graph_Fixture_Hun
{
public:
	Graph_Fixture_Hun()
	{
		testGraph = new Graph_Hun();
	}
	~Graph_Fixture_Hun()
	{
		delete testGraph;
	}
	Graph_Hun * testGraph;
};

BOOST_FIXTURE_TEST_SUITE(Graph_Test_Suite_Hun, Graph_Fixture_Hun)

BOOST_AUTO_TEST_CASE( Hungarian )
{
	int firstVex[] = { 
		0, 0, 0, 
		1, 1,
		2, 2, 2,
		3, 3, 3, 
		4, 
		5,
		6, 7, 9,
		7, 10,
		6, 9, 12,
		8, 9, 11,
		9,
		9 };
	int secondVex[] = {
		6, 7, 9,
		7, 10,
		6, 9, 12, 
		8, 9, 11,
		9,
		9,
		0, 0, 0,
		1, 1,
		2, 2, 2,
		3, 3, 3,
		4,
		5
	};
	//int firstVex[] = {
	//	0, 0,
	//	1,
	//	2, 3,
	//	2};
	//int secondVex[] = {
	//	2, 3,
	//	2,
	//	0, 0,
	//	1};
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, len);
	testGraph->setNumOfLeft(6);
	testGraph->setNumOfRight(7);
	testGraph->hungarian();

}

BOOST_AUTO_TEST_SUITE_END()