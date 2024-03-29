#define BOOST_TEST_MODULE Graph_Test_Module

#include "stdafx.h"
#include <vector>
#include "../Graph/BFS_n_DFS.h"

struct Graph_Fixture_BD
{
public:
	Graph_Fixture_BD()
	{
		testGraph = new Graph_BD;
	}
	~Graph_Fixture_BD()
	{
		delete testGraph;
	}
	Graph_BD * testGraph;
};

BOOST_FIXTURE_TEST_SUITE(Graph_Test_Suite_BD, Graph_Fixture_BD)

BOOST_AUTO_TEST_CASE( Basic )
{
	int firstVex[] = { 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5 };
	int secondVex[] = { 2, 1, 5, 0, 2, 0, 1, 3, 4, 5, 4, 2, 3, 2, 3, 0 };
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, len);

	BOOST_REQUIRE(testGraph->V() == 6);
	BOOST_REQUIRE(testGraph->E() == 8);

	vector<int> adjVexes = testGraph->adj(0);
	int sz = adjVexes.size();
	for (int i = 0; i < sz; i++)
	{
		BOOST_REQUIRE(adjVexes[i] == secondVex[i]);
	}

}

BOOST_AUTO_TEST_CASE( BFS )
{
	int firstVex[] = { 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5 };
	int secondVex[] = { 2, 1, 5, 0, 2, 0, 1, 3, 4, 5, 4, 2, 3, 2, 3, 0 };
	int len = sizeof(firstVex) / sizeof(int);
 	testGraph->init(firstVex, secondVex, len);

	testGraph->BFS();
	vector<int> firstVexes = getFirstVexes(*testGraph);
	vector<int> secondVexes = getSecondVexes(*testGraph);

	vector<int> pathTo_5 = testGraph->pathTo(5);
	int path[] = { 0, 5 };
	for (int i = 1; i > -1; i--)
	{
		BOOST_REQUIRE(pathTo_5[i] == path[1 - i]);
	}
}

BOOST_AUTO_TEST_CASE( DFS )
{
	int firstVex[] = { 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5 };
	int secondVex[] = { 2, 1, 5, 0, 2, 0, 1, 3, 4, 5, 4, 2, 3, 2, 3, 0 };
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, len);

	testGraph->DFS();
	vector<int> firstVexes = getFirstVexes(*testGraph);
	vector<int> secondVexes = getSecondVexes(*testGraph);

	vector<int> pathTo_5 = testGraph->pathTo(5);
	int path[] = {0, 2, 3, 5};
	for (int i = 3; i > -1; i--)
	{
		BOOST_REQUIRE(pathTo_5[i] == path[3 - i]);
	}
}

BOOST_AUTO_TEST_SUITE_END()