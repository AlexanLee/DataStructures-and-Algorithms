#include "BFS_n_DFS.h"
#include "Queue.hpp"
#include <iostream>
#include <map>
#include <cassert>
using namespace std;

Graph::Graph()
{
	vexNum = 0;
	edgeNum = 0;
	for (int i = 0; i < MAXNUM; i++)
	{
		vexNode[i].id = i;
		vexNode[i].isVisited = false;
		vexNode[i].distance = 0;
		vexNode[i].firstEdge = nullptr;
		edgeTo[i] = -1;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		ENode * edgePtr = vexNode[i].firstEdge;
		ENode * tmpPtr;
		while (edgePtr != nullptr)
		{
			tmpPtr = edgePtr->nextEdge;
			delete edgePtr;
			edgePtr = tmpPtr;
		}
		vexNode[i].firstEdge = nullptr;
		edgePtr = nullptr;
		tmpPtr = nullptr;
	}
}

void Graph::init(int * firstVex, int * secondVex, int len)
{
	assert(len >= 0);
	map<int, int> vexMap;
	map<int, vector<int> > edgeMap;
	for (int i = 0; i < len; i++)
	{
		bool isSuccess = addEdge(firstVex[i], secondVex[i]);
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

bool Graph::addEdge(int firstVex, int secondVex)
{
	assert(firstVex >= 0 && firstVex < MAXNUM);
	assert(secondVex >= 0 && secondVex < MAXNUM);

	ENode * edge = new ENode;
	edge->firstVex = secondVex;
	edge->nextEdge = nullptr;

	ENode * edgePtr = vexNode[firstVex].firstEdge;
	ENode * parentEdgePtr;
	if (edgePtr == nullptr)
	{
		vexNode[firstVex].firstEdge = edge;
	}
	else
	{
		while (edgePtr != nullptr)
		{
			if (edgePtr->firstVex == secondVex)	// If there has been a repeated edge
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

void Graph::BFS()
{
	// just for test
	firstVexes.clear();
	secondVexes.clear();

	BFS(vexNode[0].id);
}

void Graph::BFS(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	Queue<VNode, MAXNUM> queue;
	vexNode[vexID].isVisited = true;
	queue.enQueue(vexNode[vexID]);
	while(!queue.isEmpty())
	{
		VNode currentVex = queue.deQueue();
		vector<int> adjVexes = adj(currentVex.id);
		int sz = adjVexes.size();
		for (int i = 0; i < sz; i++)
		{
			int adjVex = adjVexes[i];

			// just for test
			firstVexes.push_back(currentVex.id);
			secondVexes.push_back(vexNode[adjVex].id);

			if (!vexNode[adjVex].isVisited)
			{
				vexNode[adjVex].isVisited = true;
				vexNode[adjVex].distance = currentVex.distance + 1;
				edgeTo[adjVex] = currentVex.id;
				queue.enQueue(vexNode[adjVex]);
			}
		}
	}
}

void Graph::DFS()
{
	// just for test
	firstVexes.clear();
	secondVexes.clear();

	DFS(vexNode[0].id);
}

void Graph::DFS(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vexNode[vexID].isVisited = true;
	vector<int> adjVexes = adj(vexID);
	int sz = adjVexes.size();
	for (int i = 0; i < sz; i++)
	{
		int adjVex = adjVexes[i];

		// just for test
		firstVexes.push_back(vexID);
		secondVexes.push_back(vexNode[adjVex].id);

		if (!vexNode[adjVex].isVisited)
		{
			vexNode[adjVex].distance = vexNode[vexID].distance + 1;
			edgeTo[adjVex] = vexID;
			DFS(adjVex);
		}
	}
}

vector<int> Graph::pathTo(int vexID)
{
	vector<int> path;
	if (edgeTo[vexID] != -1)
	{
		int id = vexID;
		int defSource = 0;	// our default source of path is at 0.
		path.push_back(vexID);
		while (edgeTo[id] != 0)
		{
			path.push_back(edgeTo[id]);
			id = edgeTo[id];
		}
		path.push_back(defSource);
	}
	return path;
}

vector<int> Graph::adj(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vector<int> ret;
	ENode * edgPtr = vexNode[vexID].firstEdge;
	while (edgPtr != nullptr)
	{
		ret.push_back(edgPtr->firstVex);
		edgPtr = edgPtr->nextEdge;
	}
	return ret;
}

int Graph::V()
{
	return vexNum;
}

int Graph::E()
{
	return edgeNum;
}

vector<int> getFirstVexes(Graph & graph)
{
	return graph.firstVexes;
}

vector<int> getSecondVexes(Graph & graph)
{
	return graph.secondVexes;
}