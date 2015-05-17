
#include "stdafx.h"
#include "../Graph/Prim_n_Kruskal.h"

struct Graph_Fixture_PK
{
public:
	Graph_Fixture_PK()
	{
		testGraph = new Graph_PK();
	}
	~Graph_Fixture_PK()
	{
		delete testGraph;
	}
	Graph_PK * testGraph;
};


BOOST_FIXTURE_TEST_SUITE(Graph_Test_Suite_PK, Graph_Fixture_PK)

BOOST_AUTO_TEST_CASE( Prim )
{
	int firstVex[] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3,
					   4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7 };
	int secondVex[] = { 2, 4, 6, 7, 2, 3, 5, 7, 0, 1, 3, 6, 7, 1, 2, 6, 
						0, 5, 6, 7, 1, 4, 7, 0, 2, 3, 4, 0, 1, 2, 4, 5 };
	double weight[] = { 0.26, 0.38, 0.58, 0.16, 0.36, 0.29, 0.32, 0.19, 0.26, 0.36, 0.17, 0.40, 0.34, 0.29, 0.17, 0.52,
		0.38, 0.35, 0.93, 0.37, 0.32, 0.35, 0.28, 0.58, 0.40, 0.52, 0.93, 0.16, 0.19, 0.34, 0.37, 0.28 };
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, weight, len);
	testGraph->Prim();

}

BOOST_AUTO_TEST_CASE( Kruskal )
{
	int firstVex[] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3,
		4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7 };
	int secondVex[] = { 2, 4, 6, 7, 2, 3, 5, 7, 0, 1, 3, 6, 7, 1, 2, 6,
		0, 5, 6, 7, 1, 4, 7, 0, 2, 3, 4, 0, 1, 2, 4, 5 };
	double weight[] = { 0.26, 0.38, 0.58, 0.16, 0.36, 0.29, 0.32, 0.19, 0.26, 0.36, 0.17, 0.40, 0.34, 0.29, 0.17, 0.52,
		0.38, 0.35, 0.93, 0.37, 0.32, 0.35, 0.28, 0.58, 0.40, 0.52, 0.93, 0.16, 0.19, 0.34, 0.37, 0.28 };
	int len = sizeof(firstVex) / sizeof(int);
	testGraph->init(firstVex, secondVex, weight, len);
	testGraph->Kruskal();

}

BOOST_AUTO_TEST_SUITE_END()
