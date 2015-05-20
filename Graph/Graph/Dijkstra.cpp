#include "Dijkstra.h"
#include <cassert>
#include <map>
#include <algorithm>

Graph_Dij::Graph_Dij()
{
	vexNum = 0;
	edgeNum = 0;
	for (int i = 0; i < MAXNUM; i++)
	{
		vexNode_Dij[i].id = i;
		vexNode_Dij[i].firstEdge = nullptr;
		edgeTo[i] = -1;	
		distTo[i] = -1;	// '-1' means infinity
	}
}

Graph_Dij::~Graph_Dij()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		ENode_Dij * edgePtr = vexNode_Dij[i].firstEdge;
		ENode_Dij * tmpPtr;
		while (edgePtr != nullptr)
		{
			tmpPtr = edgePtr->nextEdge;
			delete edgePtr;
			edgePtr = tmpPtr;
		}
		vexNode_Dij[i].firstEdge = nullptr;
		edgePtr = nullptr;
		tmpPtr = nullptr;
	}
}

void Graph_Dij::init(int * firstVex, int * secondVex, double * weight, int len)
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

bool Graph_Dij::addEdge(int firstVex, int secondVex, double weight)
{
	assert(firstVex >= 0 && firstVex < MAXNUM);
	assert(secondVex >= 0 && secondVex < MAXNUM);
	assert(firstVex != secondVex);
	assert(weight >= 0 && weight <= 1);

	ENode_Dij * edge = new ENode_Dij;
	edge->firstVex = firstVex;
	edge->secondVex = secondVex;
	edge->weight = weight;
	edge->nextEdge = nullptr;

	ENode_Dij * edgePtr = vexNode_Dij[firstVex].firstEdge;
	ENode_Dij * parentEdgePtr;
	if (edgePtr == nullptr)
	{
		vexNode_Dij[firstVex].firstEdge = edge;
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

void Graph_Dij::Dijkstra()
{
	Dijkstra(0);
}

void Graph_Dij::Dijkstra(int vexID)
{
	distTo[vexID] = 0.0;
	untrackedVexes.enQueue(vexID);
	while (!untrackedVexes.isEmpty())
	{
		relax(untrackedVexes.front());
	}

}

void Graph_Dij::relax(int vexID)
{
	untrackedVexes.deQueue();
	vector<int> adjVexes = adj(vexID);
	vector<int>::iterator itr = adjVexes.begin();
	for (; itr != adjVexes.end(); itr++)
	{
		int tmpVex = *itr;
		double weight = 0;
		ENode_Dij * edgPtr = vexNode_Dij[vexID].firstEdge;
		while (edgPtr != nullptr)
		{
			if (edgPtr->secondVex == tmpVex)
			{
				weight = edgPtr->weight;
				break;
			}
			edgPtr = edgPtr->nextEdge;
		}
		if (distTo[tmpVex] == -1 || distTo[tmpVex] > distTo[vexID] + weight )
		{
			distTo[tmpVex] = distTo[vexID] + weight;
			edgeTo[tmpVex] = vexID;
			if (!untrackedVexes.isExist(tmpVex))
			{
				untrackedVexes.enQueue(tmpVex);
			}
		}
	}
}

vector<int> Graph_Dij::adj(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vector<int> ret;
	ENode_Dij * edgPtr = vexNode_Dij[vexID].firstEdge;
	while (edgPtr != nullptr)
	{
		ret.push_back(edgPtr->secondVex);
		edgPtr = edgPtr->nextEdge;
	}
	return ret;
}

int Graph_Dij::V()
{
	return vexNum;
}

int Graph_Dij::E()
{
	return edgeNum;
}
