#include "stdafx.h"
#include "../Graph/Dijkstra.h"

struct Graph_Fixture_Dij
{
public:
	Graph_Fixture_Dij()
	{
		testGraph = new Graph_Dij();
	}
	~Graph_Fixture_Dij()
	{
		delete testGraph;
	}
	Graph_Dij * testGraph;
};

BOOST_FIXTURE_TEST_SUITE(Graph_Test_Suite_Dij, Graph_Fixture_Dij)

BOOST_AUTO_TEST_CASE( Dijkstra )
{
	int firstVex[] = { 4, 5, 4, 5, 7, 5, 0, 0, 7, 1, 2, 6, 3, 6, 6 };
	int secondVex[] = { 5, 4, 7, 7, 5, 1, 4, 2, 3, 3, 7, 2, 6, 0, 4 };
	double weight[] = { 0.35, 0.35, 0.37, 0.28, 0.28, 0.32, 0.38, 0.26, 
		0.39, 0.29, 0.34, 0.40, 0.52, 0.58, 0.93};
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, weight, len);
	testGraph->Dijkstra();

}

BOOST_AUTO_TEST_SUITE_END()
