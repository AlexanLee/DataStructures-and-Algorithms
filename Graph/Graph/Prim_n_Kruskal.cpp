#include "Prim_n_Kruskal.h"
#include <cassert>
#include <algorithm>

Graph_PK::Graph_PK()
{
	vexNum = 0;
	edgeNum = 0;
	for (int i = 0; i < MAXNUM; i++)
	{
		vexNode_PK[i].id = i;
		vexNode_PK[i].isVisited = false;
		vexNode_PK[i].firstEdge = nullptr;
		edgeTo[i] = -1;
	}
}

Graph_PK::~Graph_PK()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		ENode_PK * edgePtr = vexNode_PK[i].firstEdge;
		ENode_PK * tmpPtr;
		while (edgePtr != nullptr)
		{
			tmpPtr = edgePtr->nextEdge;
			delete edgePtr;
			edgePtr = tmpPtr;
		}
		vexNode_PK[i].firstEdge = nullptr;
		edgePtr = nullptr;
		tmpPtr = nullptr;
	}
}

void Graph_PK::init(int * firstVex, int * secondVex, double * weight, int len)
{
	assert(len >= 0);
	map<int, int> vexMap;
	map<int, vector<int> > edgeMap;
	for (int i = 0; i < len; i++)
	{
		bool isSuccess = addEdge(firstVex[i], secondVex[i], weight[i]);
		// assist in calculating vexNum & edgeNum
		if (isSuccess)
		{
			vexMap[firstVex[i]] = firstVex[i];
			vexMap[secondVex[i]] = secondVex[i];			// in a undirected graph, it is unnecessary, but in a directed graph, it is needed.
			edgeMap[firstVex[i]].push_back(secondVex[i]);	// repeated edge has been remove in addEdge
		}
	}

	// to calculate vexNum & edgeNum
	vexNum = vexMap.size();
	map<int, vector<int> >::iterator itr = edgeMap.begin();
	for (; itr != edgeMap.end(); itr++)
	{
		edgeNum += itr->second.size();
	}
	edgeNum /= 2;
}

bool Graph_PK::addEdge(int firstVex, int secondVex, double weight)
{
	assert(firstVex >= 0 && firstVex < MAXNUM);
	assert(secondVex >= 0 && secondVex < MAXNUM);
	assert(firstVex != secondVex);
	assert(weight >= 0 && weight <= 1);

	ENode_PK * edge = new ENode_PK;
	edge->firstVex = firstVex;
	edge->secondVex = secondVex;
	edge->weight = weight;
	edge->nextEdge = nullptr;

	ENode_PK * edgePtr = vexNode_PK[firstVex].firstEdge;
	ENode_PK * parentEdgePtr;
	if (edgePtr == nullptr)
	{
		vexNode_PK[firstVex].firstEdge = edge;
	}
	else
	{
		while (edgePtr != nullptr)
		{
			if (edgePtr->secondVex == secondVex)	// If there has been a repeated edge
			{
				delete edge;
				return false;
			}
			parentEdgePtr = edgePtr;
			edgePtr = edgePtr->nextEdge;
		}
		parentEdgePtr->nextEdge = edge;
	}
	return true;
}

void Graph_PK::Prim()
{
	Prim(0);
}

void Graph_PK::Prim(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);

	//vexNode_PK[vexID].isVisited = true;	// 这里不置为true是为了最后让程序自动将离vexID最近的点添加
	visitedNode.enQueue(vexNode_PK[vexID]);

	for (int i = 0; i < vexNum; i++)
	{
		Queue<VNode_PK, MAXNUM> tmpVisitedNode;
		int tmpFirstVex = -1;
		int tmpSecondVex = -1;
		double minWeight = 1.00001;
		while (!visitedNode.isEmpty())
		{
			VNode_PK tmpNode = visitedNode.deQueue();
			tmpVisitedNode.enQueue(tmpNode);
			ENode_PK * edgPtr = tmpNode.firstEdge;
			while (edgPtr != nullptr)
			{
				if (edgPtr->weight < minWeight && !vexNode_PK[edgPtr->secondVex].isVisited)
				{
					minWeight = edgPtr->weight;
					tmpFirstVex = edgPtr->firstVex;
					tmpSecondVex = edgPtr->secondVex;
				}
				edgPtr = edgPtr->nextEdge;
			}
		}
		vexNode_PK[tmpSecondVex].isVisited = true;
		edgeTo[tmpSecondVex] = tmpFirstVex;
		tmpVisitedNode.enQueue(vexNode_PK[tmpSecondVex]);

		while (!tmpVisitedNode.isEmpty())
		{
			visitedNode.enQueue(tmpVisitedNode.deQueue());
		}
	}
}

void Graph_PK::Kruskal()
{
	// remove repeated edges
	vector<map<map<int, int>, double> > unRepeatEdges;
	for (int i = 0; i < MAXNUM; i++)
	{
		if (vexNode_PK[i].firstEdge != nullptr)
		{
			ENode_PK * edgPtr = vexNode_PK[i].firstEdge;
			while (edgPtr != nullptr)
			{
				map<int, int> tmpEdge1;
				int firstVex = edgPtr->firstVex < edgPtr->secondVex ? edgPtr->firstVex : edgPtr->secondVex;
				int secondVex = edgPtr->firstVex > edgPtr->secondVex ? edgPtr->firstVex : edgPtr->secondVex;
				tmpEdge1[firstVex] = secondVex;
				map<map<int, int>, double> tmpEdge2;
				tmpEdge2.insert(map<map<int, int>, double>::value_type(tmpEdge1, edgPtr->weight));
				if (find(unRepeatEdges.begin(), unRepeatEdges.end(), tmpEdge2) == unRepeatEdges.end())
				{
					unRepeatEdges.push_back(tmpEdge2);
				}
				edgPtr = edgPtr->nextEdge;
			}
		}
	}
	// sort edges by their values
	int sz = unRepeatEdges.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = sz - 1; j > i; j--)
		{
			map<map<int, int>, double>::iterator curEdgeItr = unRepeatEdges[j].begin();
			map<map<int, int>, double>::iterator nextEdgeItr = unRepeatEdges[j - 1].begin();
			map<map<int, int>, double> tmpEdge;
			if (curEdgeItr->second < nextEdgeItr->second)
			{
				tmpEdge = unRepeatEdges[j];
				unRepeatEdges[j] = unRepeatEdges[j - 1];
				unRepeatEdges[j - 1] = tmpEdge;
			}
		}
	}
	// routing
	for (int i = 0; i < sz; i++)
	{
		map<map<int, int>, double>::iterator itr = unRepeatEdges[i].begin();
		map<int, int> tmpEdge = itr->first;
		map<int, int>::iterator edgItr = tmpEdge.begin();
		if (!vexNode_PK[edgItr->first].isVisited || !vexNode_PK[edgItr->second].isVisited)
		{
			edgeTo[edgItr->first] = edgItr->second;
			if (!vexNode_PK[edgItr->second].isVisited)
			{
				edgeTo[edgItr->second] = edgItr->first;
			}
			vexNode_PK[edgItr->first].isVisited = true;
			vexNode_PK[edgItr->second].isVisited = true;
		}
	}

}

vector<int> Graph_PK::adj(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vector<int> ret;
	ENode_PK * edgPtr = vexNode_PK[vexID].firstEdge;
	while (edgPtr != nullptr)
	{
		ret.push_back(edgPtr->secondVex);
		edgPtr = edgPtr->nextEdge;
	}
	return ret;
}

int Graph_PK::V()
{
	return vexNum;
}

int Graph_PK::E()
{
	return edgeNum;
}